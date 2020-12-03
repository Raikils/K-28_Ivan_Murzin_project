#include "plot.h"

QString Plot::name() const
{
    return _name;
}

void Plot::setName(const QString &name)
{
    _name = name;
}

QColor Plot::background() const
{
    return _background;
}

void Plot::setBackground(const QColor &background)
{
    _background = background;
}

int Plot::num() const
{
    return _num;
}

void Plot::setNum(int num)
{
    _num = num;
}

QVector<QColor> Plot::color_bars() const
{
    return _color_bars;
}

void Plot::setColor_bars(const QVector<QColor> &color_bars)
{
    _color_bars = color_bars;
}

QVector<QString> Plot::name_bars() const
{
    return _name_bars;
}

void Plot::setName_bars(const QVector<QString> &name_bars)
{
    _name_bars = name_bars;
}

QString Plot::xAxis() const
{
    return _xAxis;
}

void Plot::setXAxis(const QString &xAxis)
{
    _xAxis = xAxis;
}

QString Plot::yAxis() const
{
    return _yAxis;
}

void Plot::setYAxis(const QString &yAxis)
{
    _yAxis = yAxis;
}

bool Plot::main_x() const
{
    return _main_x;
}

void Plot::setMain_x(bool main_x)
{
    _main_x = main_x;
}

bool Plot::legend() const
{
    return _legend;
}

void Plot::setLegend(bool legend)
{
    _legend = legend;
}

QListWidgetItem *Plot::listWidgetItem() const
{
    return _listWidgetItem;
}

void Plot::setListWidgetItem(QListWidgetItem *listWidgetItem)
{
    _listWidgetItem = listWidgetItem;
}

QVector<QVector<double> > Plot::data() const
{
    return _data;
}

void Plot::setData(const QVector<QVector<double> > &data)
{
    _data = data;
}

QVector<double> Plot::ticker() const
{
    return _ticker;
}

void Plot::setTicker(const QVector<double> &ticker)
{
    _ticker = ticker;
}

int Plot::last() const
{
    return _last;
}

void Plot::setLast(int last)
{
    _last = last;
}

Plot::Plot()
{
    
}
