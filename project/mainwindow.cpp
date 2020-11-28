#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    plots.push_back(p);
}

void MainWindow::DeleteCreatePlot()
{
    delete crpl;
}

void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    for (auto &k : plots) {
        if(k.listWidgetItem() == current) {
            ui->customPlot->setBackground(QBrush(k.gradient()));
        }
    }
}
