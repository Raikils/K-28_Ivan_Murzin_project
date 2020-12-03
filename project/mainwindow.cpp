#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    group = NULL;
    cur = -1;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CreateButton_clicked()
{
    crpl = new CreatePlot(this);
    crpl->exec();
}

void MainWindow::CreateNewPlot(Plot p)
{
    delete crpl;
    p.setListWidgetItem(new QListWidgetItem(ui->listWidget));
    p.listWidgetItem()->setText(p.name());
    QVector<QVector<double>> data;
    for (int i = 0; i < p.num(); i++) {
        data.push_back({0});
    }
    p.setData(data);
    p.setTicker({1});
    p.setLast(0);
    plots.push_back(p);
}

void MainWindow::DeleteCreatePlot()
{
    delete crpl;
}

void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    int i = 0;
    for (auto &k : plots) {
        if(k.listWidgetItem() == current) {
            rebuild(k);
            ui->customPlot->replot();
            ui->customPlot->update();
            cur = i;
            ui->spinBox_cur_tick->setValue(1);
            ui->spinBox_cur_tick->setMaximum(k.last() + 1);
            ui->comboBox_cur_bar->setCurrentIndex(0);
            //ui->comboBox_cur_bar->clear();
            if (ui->comboBox_cur_bar->count() > k.num())
            for (int j = 7; j >= k.num(); j--) {
                ui->comboBox_cur_bar->removeItem(j);
            }
            else
            for (int i = ui->comboBox_cur_bar->count() + 1; i <= k.num(); i++) {
                ui->comboBox_cur_bar->addItem(QString::number(i));
            }
            ui->doubleSpinBox_cur_data->setValue(k.data()[0][0]);
            cur = i;
            ui->customPlot->update();
            ui->customPlot->replot();
            return;
        } else i++;
    }
}

void MainWindow::rebuild(Plot p)
{
    ui->customPlot->clearPlottables();
    ui->customPlot->clearGraphs();
    ui->customPlot->clearItems();
    bars.clear();
    if (group != NULL) group->clear();
    if (group != NULL) delete group;
    group = new QCPBarsGroup(ui->customPlot);
    //ticks.clear();
    //ticks << 1 << 2 << 3;
    num = p.num();
    gradient.setColorAt(0, p.background());
    gradient.setColorAt(1, p.background());
    col_bars.clear();
    col_bars = p.color_bars();
    name_bars.clear();
    name_bars = p.name_bars();
    x_name = p.xAxis();
    y_name = p.yAxis();
    main_x = p.main_x();
    legend = p.legend();

    //QVector<double> data;
    //data << 0 << 0 << 0;
    //p.setData({data});
    //p.setTicker(ticks);
    for (int i = 0; i < num; i++) {
        if (main_x) bars.push_back(new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis));
        else bars.push_back(new QCPBars(ui->customPlot->yAxis, ui->customPlot->xAxis));
        bars[bars.size() - 1]->setAntialiased(false);
        bars[bars.size() - 1]->setStackingGap(1);
        bars[bars.size() - 1]->setName(name_bars[i]);
        bars[bars.size() - 1]->setBrush(col_bars[i]);
        bars[bars.size() - 1]->setWidth(0.3);
        bars[bars.size() - 1]->setData(p.ticker(), p.data()[i]);
        //bars[bars.size() - 1]->setData(ticks, data);
        bars[bars.size() - 1]->setBarsGroup(group);
    }
    ui->customPlot->setBackground(QBrush(gradient));
    ui->customPlot->xAxis->setRange(0, 4);
    ui->customPlot->yAxis->setRange(0, 10);
    ui->customPlot->xAxis->setLabel(x_name);
    ui->customPlot->yAxis->setLabel(y_name);
    ui->customPlot->legend->setVisible(legend);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void MainWindow::on_spinBox_cur_tick_valueChanged(int arg1)
{
    qDebug() << "ds";
    ui->comboBox_cur_bar->setCurrentIndex(0);
    if(cur >= 0) ui->doubleSpinBox_cur_data->setValue(plots[cur].data()[0][arg1 - 1]);
}

void MainWindow::on_comboBox_cur_bar_currentIndexChanged(int index)
{
    /*qDebug() << ui->spinBox_cur_tick->value() - 1 << index << cur;
    if (cur >= 0) qDebug() << plots[cur].data().size();
    if (cur >= 0) qDebug() << plots[cur].data()[0].size();
    if (cur >= 0) qDebug() << plots[cur].data()[ui->spinBox_cur_tick->value() - 1][index];*/
    if(cur >= 0) ui->doubleSpinBox_cur_data->setValue(plots[cur].data()[index][ui->spinBox_cur_tick->value() - 1]);
}

void MainWindow::on_doubleSpinBox_cur_data_valueChanged(double arg1)
{
    if(cur >= 0) { QVector<QVector<double>> data = plots[cur].data();
    data[ui->comboBox_cur_bar->currentIndex()][ui->spinBox_cur_tick->value() - 1] = arg1;
    plots[cur].setData(data);
    if (plots[cur].last() == ui->spinBox_cur_tick->value() - 1) {
        plots[cur].setLast(plots[cur].last() + 1);
        ui->spinBox_cur_tick->setMaximum(plots[cur].last() + 1);
        for (auto &k : plots[cur].data()) k << 0;
        QVector<double> tick = plots[cur].ticker();
        tick << plots[cur].last() + 1;
        plots[cur].setTicker(tick);
    }
    rebuild(plots[cur]);
    ui->customPlot->update();
    ui->customPlot->replot();
    }
}

void MainWindow::on_pushButton_Delete_clicked()
{

}
