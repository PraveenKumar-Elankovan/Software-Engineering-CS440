#ifndef ABOUTBOMB_H
#define ABOUTBOMB_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class aboutBomb;
}

class aboutBomb : public QDialog
{
    Q_OBJECT

public:
    explicit aboutBomb(QWidget *parent = 0);
    ~aboutBomb();

private slots:
    void on_buttonBox_clicked();


private:
    Ui::aboutBomb *ui;
};

#endif // ABOUTBOMB_H
