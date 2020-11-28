#ifndef PLOT_H
#define PLOT_H
#include <qcustomplot.h>
#include <QListWidgetItem>

class Plot
{
private:
    QLinearGradient _gradient;
    QCPBars * _bar;
    QCPAxis * _xAxis;
    QCPAxis * _yAxis;
    QVector<double> _data;
    QString _name;
    QListWidgetItem *_listWidgetItem;
public:
    Plot();
    QLinearGradient gradient() const;
    void setGradient(const QLinearGradient &gradient);
    QCPBars *bar() const;
    void setBar(QCPBars *bar);
    QCPAxis *xAxis() const;
    void setXAxis(QCPAxis *xAxis);
    QCPAxis *yAxis() const;
    void setYAxis(QCPAxis *yAxis);
    QVector<double> data() const;
    void setData(const QVector<double> &data);
    QString name() const;
    void setName(const QString &name);
    QListWidgetItem *listWidgetItem() const;
    void setListWidgetItem(QListWidgetItem *listWidgetItem);
};

#endif // PLOT_H
