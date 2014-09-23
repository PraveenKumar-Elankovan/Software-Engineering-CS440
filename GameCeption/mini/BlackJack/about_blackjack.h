#ifndef ABOUT_BLACKJACK_H
#define ABOUT_BLACKJACK_H

#include <QDialog>

namespace Ui {
class About_BlackJack;
}

class About_BlackJack : public QDialog
{
    Q_OBJECT

public:
    explicit About_BlackJack(QWidget *parent = 0);
    ~About_BlackJack();
private slots:
    void on_buttonBox_clicked();

private:
    Ui::About_BlackJack *ui;
};

#endif // ABOUT_BLACKJACK_H
