#include "color.h"
#include "ui_color.h"

Color::Color(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Color)
{
    ui->setupUi(this);
    //ui->graphicsView->setScene(myScene);
    ui->graphicsView->setBackgroundBrush(QBrush(QColor(0, 0, 255)));
}

Color::~Color()
{
    delete ui;
}
