#include "mini/RandomChance/randomchance.h"
#include "ui_randomchance.h"
#include <stdlib.h>

/****************
 * Do not modify
 ****************/
RandomChance::RandomChance(QWidget *parent) :
    QDialog(parent, Qt::CustomizeWindowHint  | Qt::WindowTitleHint ),
    Minigame(),
    ui(new Ui::RandomChance)
{
    ui->setupUi(this);
    ui->b_ok->setEnabled(false);

    configureGame();
}

/****************
 * Clean all minigame code
 ****************/
RandomChance::~RandomChance()
{
    for(int i = 0; i < num; i++)
        delete this->tile[i];

    delete ui;
}

/******** PRIVATE **********/

/****************
 * Configure minigame
 ****************/
void RandomChance::configureGame()
{
    srand(time(0));
    int unique = rand() % 4;
    QSizePolicy policy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    for(int i = 0; i < num; i++)
    {
        if(i == unique)
            tile[i] = new RandomChanceTile(i, true, this);
        else
            tile[i] = new RandomChanceTile(i, false, this);

        tile[i]->setSizePolicy(policy);

        connect(tile[i], SIGNAL(clicked()), this, SLOT(on_b_tile_clicked()));
    }

    tile[0]->setText(QString("Is this the \nright box?"));
    tile[1]->setText(QString("Choose carefully!"));
    tile[2]->setText(QString("Pick me!"));
    tile[3]->setText(QString("Oh no, \npick the other box!"));

    ui->g_grid->addWidget(tile[0], 0, 0);
    ui->g_grid->addWidget(tile[1], 0, 1);
    ui->g_grid->addWidget(tile[2], 1, 0);
    ui->g_grid->addWidget(tile[3], 1, 1);

}

void RandomChance::disableGame()
{
    for(int i = 0; i < num; i++)
        this->tile[i]->setEnabled(false);
}

/****************
 * Do not modify
 ****************/
void RandomChance::setWin()
{
    Minigame::setWin();

    ui->t_result->setText(QString("Win!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

/****************
 * Do not modify
 ****************/
void RandomChance::setLose()
{
    Minigame::setLose();

    ui->t_result->setText(QString("Lose!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

/****************
 * Do not modify
 ****************/
void RandomChance::quit()
{
    Minigame::quit();

    disableGame();

    ui->b_ok->setEnabled(true);
}

/******** PRIVATE SLOTS **********/


/****************
 * Set win or lose
 ****************/
void RandomChance::on_b_tile_clicked()
{
    RandomChanceTile* tile = (RandomChanceTile*)sender();

    if(tile->getUnique())
        setWin();
    else
        setLose();

    quit();
}


/****************
 * Do not modify
 ****************/
void RandomChance::on_b_ok_clicked()
{
    this->done(QDialog::Accepted);
}
