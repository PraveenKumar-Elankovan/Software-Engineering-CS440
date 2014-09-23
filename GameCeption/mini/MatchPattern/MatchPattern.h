#ifndef MPAT_H
#define MPAT_H

#include <QDialog>
#include <QAbstractButton>
#include <QTimer>
#include "main/minigame.h"

namespace Ui {
class MatchPattern;
}

class MatchPattern : public QDialog, public Minigame
{
    Q_OBJECT

public:
    explicit MatchPattern(QWidget *parent = 0);
    ~MatchPattern();

private slots:
    void on_b_ok_clicked();
    void myquit();
    void showPattern();
    void startClock();
    void checkForWin();
    void sendNumFromButton1();
    void sendNumFromButton2();
    void sendNumFromButton3();
    void sendNumFromButton4();
    void sendNumFromButton5();
    void sendNumFromButton6();
    void sendNumFromButton7();
    void sendNumFromButton8();

private:
    Ui::MatchPattern *ui;

    int pattern[6];
    //hold the values received from player
    int patternReceivedFromPlayer[6];
    //hold where in the pattern the palyer is
    int indexInThePattern;

    bool isPatternInitialized;
    bool flashTheSquare;
    int squareToFlash;
    QTimer *timer;


    void configureGame();
    void disableGame();
    void setWin();
    void setLose();
    void quit();
};

#endif // MINI1_H
