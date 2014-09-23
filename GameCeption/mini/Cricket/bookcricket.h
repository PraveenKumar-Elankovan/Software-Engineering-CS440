#ifndef BOOKCRICKET_H
#define BOOKCRICKET_H

#include <QDialog>
#include <QAbstractButton>
#include <QSizePolicy>
#include <QTimer>
#include <QDateTime>
#include <unistd.h>
#include "../../main/minigame.h"
#include "aboutbookcricket.h"

#define num4 6

namespace Ui {
class bookcricket;
}

class bookcricket : public QDialog, public Minigame
{
    Q_OBJECT

public:
    explicit bookcricket(QWidget *parent = 0);
    ~bookcricket();

private slots:

    void on_playerButton_clicked();

    void on_computerButton_clicked();

    void startGame();

    void on_b_ok_clicked();
    void on_b_about_clicked();


private:
    Ui::bookcricket *ui;
private:
    int playerTotalScore;
    int computerTotalScore;
    int counter;

    void configureGame();
    void setWin();
    void setLose();
    void quit();
};

#endif // BOOKCRICKET_H
