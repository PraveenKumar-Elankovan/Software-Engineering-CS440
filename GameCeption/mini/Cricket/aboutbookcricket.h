#ifndef ABOUTBOOKCRICKET_H
#define ABOUTBOOKCRICKET_H

#include <QDialog>

namespace Ui {
class aboutbookcricket;
}

class aboutbookcricket : public QDialog
{
    Q_OBJECT

public:
    explicit aboutbookcricket(QWidget *parent = 0);
    ~aboutbookcricket();

private slots:
    void on_pushButton_clicked();

private:
    Ui::aboutbookcricket *ui;
};

#endif // ABOUTBOOKCRICKET_H
