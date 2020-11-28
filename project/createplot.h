#ifndef CREATEPLOT_H
#define CREATEPLOT_H

#include <QDialog>
#include <plot.h>

namespace Ui {
class CreatePlot;
}

class CreatePlot : public QDialog
{
    Q_OBJECT

public:
    explicit CreatePlot(QWidget *parent = nullptr);
    ~CreatePlot();

signals:
    void CreateNewPlot(Plot p);
    void DeleteCreatePlot();

private slots:
    void on_OkButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::CreatePlot *ui;
    Plot plot;
};

#endif // CREATEPLOT_H
