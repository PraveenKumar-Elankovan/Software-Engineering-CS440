#ifndef BLACKJACK_H
#define BLACKJACK_H


#include "main/minigame.h"
#include "mini/BlackJack/blackjacktile.h"
#include "mini/BlackJack/about_blackjack.h"
#include <QDialog>
#include <QAbstractButton>
#define num2 3

namespace Ui {
class BlackJack;
}

class BlackJack : public QDialog, public Minigame
{
    Q_OBJECT

public:
    explicit BlackJack(QWidget *parent = 0);

    ~BlackJack();

private slots:
     void on_b_about_clicked();
    void on_b_ok_clicked();
    void on_Hit_Button_clicked();
    void on_Draw_Button_clicked();
    void setBustUser();
    void setBustAI();


private:
    Ui::BlackJack* ui;
    BlackJackTile* tile[num2];
    void configureGame(int);
    void configureAIGame(int);
    void disableGame();
    void setWin();
    void setLose();
    void quit();
    void printOutput(int);
};

#endif // MINIROLLCHANCE_H

