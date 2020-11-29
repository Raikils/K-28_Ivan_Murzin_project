#include "createplot.h"
#include "ui_createplot.h"

CreatePlot::CreatePlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePlot)
{
    ui->setupUi(this);
    connect(this,SIGNAL(CreateNewPlot(Plot)),parent,SLOT(CreateNewPlot(Plot)));
    connect(this,SIGNAL(DeleteCreatePlot()),parent,SLOT(DeleteCreatePlot()));
    ui->comboBox_backcolor->addItem("whiet");
    ui->comboBox_backcolor->addItem("red");
    ui->comboBox_backcolor->addItem("green");
    ui->comboBox_backcolor->addItem("blue");
    ui->comboBox_barcolor->addItem("red");
    ui->comboBox_barcolor->addItem("green");
    ui->comboBox_barcolor->addItem("blue");
    gradient.setColorAt(0, QColor(255, 255, 255));
    gradient.setColorAt(1, QColor(255, 255, 255));
    ui->customPlot->setBackground(QBrush(gradient));

    f = new QCustomPlot(this);
    f->setVisible(true);
    f->setMinimumSize(100, 100);

    bar = new QCPBars(f->xAxis, f->yAxis);
    bar->setAntialiased(false);
    bar->setStackingGap(1);
    bar->setName("name");
    bar->setWidth(100);
    bar->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    bar->setBrush(QColor(255, 0, 0));

    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3;
    labels << "1" << "2" << "3";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    QVector<double> data;
    data  << 4 << 3 << 3;
    bar->setData(ticks, data);

    f->yAxis->setLabel("Power Consumption in\nKilowatts per Capita (2007)");

    bar->setWidth(1);
}

CreatePlot::~CreatePlot()
{
    delete ui;
}

void CreatePlot::on_OkButton_clicked()
{
    plot.setName(ui->lineEdit_name->text());
    emit CreateNewPlot(plot);
}

void CreatePlot::on_CancelButton_clicked()
{
    emit DeleteCreatePlot();
}

void CreatePlot::on_comboBox_backcolor_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "red") {
        gradient.setColorAt(0, QColor(255, 0, 0));
        gradient.setColorAt(1, QColor(255, 0, 0));
    }
    if (arg1 == "green") {
        gradient.setColorAt(0, QColor(0, 255, 0));
        gradient.setColorAt(1, QColor(0, 255, 0));
    }
    if (arg1 == "blue") {
        gradient.setColorAt(0, QColor(0, 0, 255));
        gradient.setColorAt(1, QColor(0, 0, 255));
    }
    if (arg1 == "whiet") {
        gradient.setColorAt(0, QColor(255, 255, 255));
        gradient.setColorAt(1, QColor(255, 255, 255));
    }
    ui->customPlot->setBackground(QBrush(gradient));
}

void CreatePlot::on_comboBox_barcolor_currentIndexChanged(const QString &arg1)
{
    /*if (arg1 == "red") {
        bar->setPen(QPen(QColor(111, 9, 176).lighter(170)));
        bar->setBrush(QColor(255, 0, 0)); qDebug() << "r";
    }
    if (arg1 == "green") {
        bar->setPen(QPen(QColor(111, 9, 176).lighter(170)));
        bar->setBrush(QColor(0, 255, 0)); qDebug() << "g";
    }
    if (arg1 == "blue") {
        bar->setPen(QPen(QColor(111, 9, 176).lighter(170)));
        bar->setBrush(QColor(0, 0, 255)); qDebug() << "b";
    }*/
}

void CreatePlot::on_pushButton_clicked()
{
    /*bar->setKeyAxis(ui->customPlot->yAxis);
    bar->setValueAxis(ui->customPlot->xAxis);*/
    //delete f;
    bar->setWidth(5);
    bar->setPen(QPen(QColor(238, 244, 66).lighter(170)));
    bar->setBrush(QColor(238, 244, 66));
    f->yAxis->setLabel("owatts pe Capita (2007)");
    gradient.setColorAt(0, QColor(0, 0, 255));
    gradient.setColorAt(1, QColor(0, 0, 255));
    f->setBackground(QBrush(gradient));
    f->replot();
    f->update();
}
