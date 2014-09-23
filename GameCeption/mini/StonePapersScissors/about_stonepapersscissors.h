#ifndef ABOUT_STONEPAPERSSCISSORS_H
#define ABOUT_STONEPAPERSSCISSORS_H

#include <QDialog>
#include <QAbstractButton>
namespace Ui {
class About_StonePapersScissors;
}

class About_StonePapersScissors : public QDialog
{
    Q_OBJECT

public:
    explicit About_StonePapersScissors(QWidget *parent = 0);
    ~About_StonePapersScissors();

private slots:
    void on_buttonBox_clicked();

private:
    Ui::About_StonePapersScissors *ui;
};

#endif // ABOUT_STONEPAPERSSCISSORS_H
