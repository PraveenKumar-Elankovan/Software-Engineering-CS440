#ifndef MINIROLLCHANCE_H
#define MINIROLLCHANCE_H

#include <QDialog>
#include <QAbstractButton>
#include "main/minigame.h"
#include "mini/RandomChance/randomchancetile.h"

#define num 4

namespace Ui{
class RandomChance;
}

class RandomChance : public QDialog, public Minigame
{
    Q_OBJECT

public:
    explicit RandomChance(QWidget *parent = 0);
    ~RandomChance();

private slots:
    void on_b_tile_clicked();

    void on_b_ok_clicked();

private:
    Ui::RandomChance* ui;
    RandomChanceTile* tile[num];

    void configureGame();
    void disableGame();
    void setWin();
    void setLose();
    void quit();
};

#endif // MINIROLLCHANCE_H
