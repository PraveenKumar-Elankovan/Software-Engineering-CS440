#ifndef WDTD_H
#define DTD_H

#include <QDialog>
#include <QAbstractButton>
#include <QTimer>
#include "main/minigame.h"

namespace Ui {
class LuckAndSkill;
}

class LuckAndSkill : public QDialog, public Minigame
{
    Q_OBJECT

public:
    explicit LuckAndSkill(QWidget *parent = 0);
    ~LuckAndSkill();

private slots:
    void on_b_ok_clicked();
    void start();
    void stop();
    void startTimer();
    void generateRandomNumber();

private:
    Ui::LuckAndSkill* ui;

    int randomNumberYouGotToBeat;
    int numberYouGot;
    bool canYouPlay;
    int numberOfTimesStartWasPressed;
    QTimer *timer;

    void configureGame();
    void disableGame();
    void setWin();
    void setLose();
    void quit();
    //void generateRandomNumber();
};

#endif // MINI1_H
