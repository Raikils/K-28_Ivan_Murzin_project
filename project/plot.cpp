#include "plot.h"

QLinearGradient Plot::gradient() const
{
    return _gradient;
}

void Plot::setGradient(const QLinearGradient &gradient)
{
    _gradient = gradient;
}

QCPBars *Plot::bar() const
{
    return _bar;
}

void Plot::setBar(QCPBars *bar)
{
    _bar = bar;
}

QCPAxis *Plot::xAxis() const
{
    return _xAxis;
}

void Plot::setXAxis(QCPAxis *xAxis)
{
    _xAxis = xAxis;
}

QCPAxis *Plot::yAxis() const
{
    return _yAxis;
}

void Plot::setYAxis(QCPAxis *yAxis)
{
    _yAxis = yAxis;
}

QVector<double> Plot::data() const
{
    return _data;
}

void Plot::setData(const QVector<double> &data)
{
    _data = data;
}

QString Plot::name() const
{
    return _name;
}

void Plot::setName(const QString &name)
{
    _name = name;
}

QListWidgetItem *Plot::listWidgetItem() const
{
    return _listWidgetItem;
}

void Plot::setListWidgetItem(QListWidgetItem *listWidgetItem)
{
    _listWidgetItem = listWidgetItem;
}

Plot::Plot()
{

}
