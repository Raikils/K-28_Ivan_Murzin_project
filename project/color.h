#ifndef COLOR_H
#define COLOR_H

#include <QDialog>

namespace Ui {
class Color;
}

class Color : public QDialog
{
    Q_OBJECT

public:
    explicit Color(QWidget *parent = nullptr);
    ~Color();

private:
    Ui::Color *ui;
};

#endif // COLOR_H
