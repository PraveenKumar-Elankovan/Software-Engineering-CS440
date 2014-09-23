#ifndef STONEPAPERSSCISSORS_H
#define STONEPAPERSSCISSORS_H
#include "main/minigame.h"
#include "mini/StonePapersScissors/stonepapersscissorstile.h"
#include "mini/StonePapersScissors/about_stonepapersscissors.h"
#include <QDialog>
#include <QAbstractButton>
#define num1 3

namespace Ui {
class StonePapersScissors;
}

class StonePapersScissors : public QDialog, public Minigame
{
    Q_OBJECT

public:
    explicit StonePapersScissors(QWidget *parent = 0);
    ~StonePapersScissors();

private slots:
    void on_b_tile_clicked();
    void on_b_about_clicked();
    void on_b_ok_clicked();

private:

    Ui::StonePapersScissors* ui;
    StonePapersScissorsTile* tile[num1];
    StonePapersScissorsTile* tileAI;

    void configureGame();
    void configureAIGrid(int);
    void disableGame();
    void setWin();
    void setLose();
    void quit();
};

#endif // MINIROLLCHANCE_H

