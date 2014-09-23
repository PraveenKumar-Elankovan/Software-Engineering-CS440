#ifndef WHACK_H
#define WHACK_H

#include <QDialog>
#include <QAbstractButton>
#include <QTimer>
#include "main/minigame.h"

namespace Ui {
class WhackMole;
}

class WhackMole : public QDialog, public Minigame
{
    Q_OBJECT

public:
    explicit WhackMole(QWidget *parent = 0);
    ~WhackMole();

private slots:
    void on_b_ok_clicked();
    void visibleMole();
    void startTheGame();
    void whiteTheButtons();
    void disconnectAllButtons();
    void checkNumberOfMolesHit();
    //emit signal
    void moleWasHit();

private:
    Ui::WhackMole* ui;

    QTimer *timer;
    int whichMoleIsShowing;
    int numberOfMolesShown;
    int numberOfMolesToHit;
    int numberOfMolesThatHaveBeenHit;

    void configureGame();
    void disableGame();
    void setWin();
    void setLose();
    void quit();
    //void generateRandomNumber();
};

#endif // MINI1_H
