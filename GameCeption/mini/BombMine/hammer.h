#ifndef HAMMER_H
#define HAMMER_H

#include <QDialog>
#include <QAbstractButton>
#include <QSizePolicy>
#include <QTimer>
#include <QDateTime>
#include <unistd.h>

#include "hammertile.h"
#include "../../main/minigame.h"
#include "aboutbomb.h"

#define num2 3

namespace Ui {
class hammer;
}

class hammer : public QDialog, public Minigame
{
    Q_OBJECT

public:
    explicit hammer(QWidget *parent = 0);
    ~hammer();

private slots:
    void on_b_about_clicked();

    void on_b_tile_clicked();

    void startGame();

    void on_b_ok_clicked();


private:
    Ui::hammer *ui;
    hammertile*** tile;
    int counter;

    void configureGame();
    void disableGame();
    void setWin();
    void setLose();
    void quit();
    void manipulate();
};

#endif // HAMMER_H
