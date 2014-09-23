#include "cointoss.h"
#include "ui_cointoss.h"
#include <stdlib.h>

/****************
 * Do not modify
 ****************/
coinToss::coinToss(QWidget *parent) :
    QDialog(parent, Qt::CustomizeWindowHint  | Qt::WindowTitleHint ),
    Minigame(),
    ui(new Ui::coinToss)
{
    ui->setupUi(this);
    ui->start_jackpot->setEnabled(false);
    ui->b_ok->setEnabled(false);
    for (int i=0; i<3; i++)
        arr[i] = 0;

    configureGame();
}

/****************
 * Clean all minigame code
 ****************/
coinToss::~coinToss()
{
    for(int i = 0; i < num1; i++)
        delete this->tile[i];

    delete ui;
}

/******** PRIVATE **********/

/****************
 * Configure minigame
 ****************/
void coinToss::configureGame()
{
    //srand(0);

    connect(ui->start_jackpot, SIGNAL(clicked()), this, SLOT(on_start_jackpot_clicked()));
    for(int i = 0; i < num1; i++)
    {
        tile[i] = new CointossTile(i, true, this);
        tile[i]->setText(QString("Slot"));
        tile[i]->setFixedSize(100, 100);

        connect(tile[i], SIGNAL(clicked()), this, SLOT(on_b_tile_clicked()));
        ui->g_grid->addWidget(tile[i], 0, i);
        tile[i]->setStyleSheet("background:Green;");
    }
    disableGame();
}

void coinToss::disableGame()
{
    for(int i = 0; i < num1; i++)
        this->tile[i]->setEnabled(false);
}

/****************
 * Do not modify
 ****************/
void coinToss::setWin()
{
    Minigame::setWin();

    ui->t_result->setText(QString("You Win!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

/****************
 * Do not modify
 ****************/
void coinToss::setLose()
{
    Minigame::setLose();

    ui->t_result->setText(QString("You Lose!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

/****************
 * Do not modify
 ****************/
void coinToss::quit()
{
    Minigame::quit();

    disableGame();

    ui->b_ok->setEnabled(true);
}

/******** PRIVATE SLOTS **********/


/****************
 * Set win or lose
 ****************/
/*void coinToss::on_b_tile_clicked()
{
    CointossTile* tile = (CointossTile*)sender();

    if(tile->getUnique())
        setWin();
    else
        setLose();

    quit();
}*/


/****************
 * Do not modify
 ****************/
void coinToss::on_b_ok_clicked()
{
    this->done(QDialog::Accepted);
}


void coinToss::on_num_1_currentTextChanged(const QString &arg1)
{
    this->selectedFirstSlotValue= arg1.toStdString();
}

void coinToss::on_num_2_currentTextChanged(const QString &arg1)
{
    this->selectedSecondSlotValue = arg1.toStdString();
}

void coinToss::on_num_3_currentTextChanged(const QString &arg1)
{
    this->selectedThirdSlotValue = arg1.toStdString();
    if (this->selectedFirstSlotValue.compare("select") != 0
            && this->selectedSecondSlotValue.compare("select") != 0
            && this->selectedThirdSlotValue.compare("select") != 0)
    {
        ui->start_jackpot->setEnabled(true);
    }

}

void coinToss::on_start_jackpot_clicked()
{
    for(int i=0; i<3; i++)
        arr[i] = rand() % 9 + 1;


    if (this->selectedFirstSlotValue.compare("select") == 0
            || this->selectedSecondSlotValue.compare("select") == 0
            || this->selectedThirdSlotValue.compare("select") == 0)
    {

        // Do nothing and ask user to give all inputs
    }

    else
    {
        ui->num_1->setEnabled(false);
        ui->num_2->setEnabled(false);
        ui->num_3->setEnabled(false);

        int input1 = this->selectedFirstSlotValue[0] - '0';
        int input2 = this->selectedSecondSlotValue[0] - '0';
        int input3 = this->selectedThirdSlotValue[0] - '0';

        for (int i=0; i<3; i++)
            tile[i]->setText(QString(arr[i] + '0'));

        if (arr[0] == input1 && arr[1] == input2 && arr[2] == input3)
        {
            setWin();
            ui->t_result->setStyleSheet("background: Green;");
        }
        else
        {
            setLose();
            ui->t_result->setStyleSheet("background: Red;");
        }
        ui->start_jackpot->setEnabled(false);
        quit();
    }
}

