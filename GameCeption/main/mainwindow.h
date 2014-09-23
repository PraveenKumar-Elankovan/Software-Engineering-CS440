#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*** QT and C standard ***/
#include <QMainWindow>
#include <QDialog>
#include <QSizePolicy>
#include <unistd.h>

/*** user defined ***/
#include "ui_mainwindow.h"
#include "main/aboutdialog.h"
#include "main/gameboardsizedialog.h"
#include "main/tile.h"
#include "main/shared.h"
#include "main/tile.h"
#include "main/selectminigamedialog.h"

/*** minigames ***/
#include "mini/RandomChance/randomchance.h"
#include "mini/Trivia/trivia.h"
#include "mini/StonePapersScissors/stonepapersscissors.h"
#include "mini/Jackpot/cointoss.h"
#include "mini/BlackJack/blackjack.h"
#include "mini/AndroidQuiz/androidquiz.h"
#include "mini/Cricket/bookcricket.h"
#include "mini/BombMine/hammer.h"
#include "mini/LuckAndSkill/luckandskill.h"
#include "mini/MatchPattern/MatchPattern.h"
#include "mini/WhackMole/WhackMole.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_b_tile_clicked();
    void on_b_singleplayer_clicked();
    void on_b_multiplayer_clicked();
    void on_b_main_menu_clicked();
    void on_b_end_game_clicked();
    void on_b_about_clicked();

private:
    Ui::MainWindow *ui;
    Tile*** tile;
    int board_size;
    int player_turn;
    int size;
    int flagAI;
    char resultArray[10][10];

    void configureBoard();
    void togglePlayer();
    void disableTileClicks();
    void enableTileClicks();
    bool playMini();
    int checkWin();
    void showWin();
    void showXWin();
    void showOWin();
    void showTie();
};

#endif // MAINWINDOW_H
