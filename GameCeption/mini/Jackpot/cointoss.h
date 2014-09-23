#ifndef COINTOSS_H
#define COINTOSS_H

#include <QDialog>
#include <QAbstractButton>
#include "main/minigame.h"
#include "mini/Jackpot/cointosstile.h"

#define num1 3

namespace Ui{
class coinToss;
}

class coinToss : public QDialog, public Minigame
{
    Q_OBJECT

public:
    explicit coinToss(QWidget *parent = 0);
    ~coinToss();
    //std::string getSelectedMinigame();

private slots:
    //void on_b_tile_clicked();

    void on_b_ok_clicked();

    void on_num_1_currentTextChanged(const QString &arg1);

    void on_num_2_currentTextChanged(const QString &arg1);

    void on_num_3_currentTextChanged(const QString &arg1);

    void on_start_jackpot_clicked();


private:
    Ui::coinToss* ui;
    CointossTile* tile[num1];
    std::string selectedFirstSlotValue;
    std::string selectedSecondSlotValue;
    std::string selectedThirdSlotValue;
    int arr[3];

    void configureGame();
    void disableGame();
    void setWin();
    void setLose();
    void quit();
};

#endif // COINTOSS_H

