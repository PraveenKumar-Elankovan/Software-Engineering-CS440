#include "bookcricket.h"
#include "ui_bookcricket.h"

#include <stdlib.h>

int flag=0;
int flagAI=0;

bookcricket::bookcricket(QWidget *parent) : QDialog(parent,
                         Qt::CustomizeWindowHint | Qt::WindowTitleHint), Minigame(),
    ui(new Ui::bookcricket)
{
    ui->setupUi(this);
    ui->b_ok->setEnabled(false);
    this->playerTotalScore = 0;
    this->computerTotalScore = 0;
    this->counter = 0;

    configureGame();
}

bookcricket::~bookcricket()
{
    delete ui;
}


void bookcricket::configureGame()
{

    connect(ui->playerButton, SIGNAL(clicked()), this, SLOT(on_playerButton_clicked()));
    connect(ui->computerButton, SIGNAL(clicked()), this, SLOT(on_computerButton_clicked()));
    connect(ui->start, SIGNAL(clicked()), this, SLOT(startGame()));

    ui->playerButton->setEnabled(false);
    ui->computerButton->setEnabled(false);
}

void bookcricket::startGame()
{
    ui->start->setEnabled(false);
    ui->playerButton->setEnabled(true);
    ui->computerButton->setEnabled(false);

}

void bookcricket::on_playerButton_clicked()
{
    if(counter % 2 ==0)
        flag=0;
    else
        flag=1;
    if(flag==0)
    {
    flag=1;
    int playerlocalScore = 0;

    this->counter++;

    playerlocalScore = rand() % num4 + 1;
    this->playerTotalScore = this->playerTotalScore + playerlocalScore;

    QString temp = QString::number(playerlocalScore);
    ui->playerButton->setText(temp);

    QString temp2 = QString::number(this->playerTotalScore);
    ui->playerTotalScore->setText(temp2);

    ui->computerButton->setText(QString("computer \n score ? "));
    ui->playerButton->setEnabled(false);
    ui->computerButton->setEnabled(true);
    }

}

void bookcricket::on_computerButton_clicked()
{
    if(counter % 2 ==0)
        flagAI=1;
    else
        flagAI=0;
    if(flagAI==0)
    {
    int computerlocalScore = 0;
    flagAI=1;
    this->counter++;

    computerlocalScore = rand() % num4 + 1;
    QString temp = QString::number(computerlocalScore);
    ui->computerButton->setText(QString(temp));

    this->computerTotalScore = this->computerTotalScore + computerlocalScore;
    QString temp2 = QString::number(this->computerTotalScore);
    ui->computerTotalScore->setText(QString(temp2));


    if (this->counter < 10)
    {
        ui->computerButton->setEnabled(false);
        ui->playerButton->setEnabled(true);
        //ui->playerButton->setText(QString(" "));
    }

    else
    {
        if(this->playerTotalScore > this->computerTotalScore)
        {
            ui->t_result->setStyleSheet("background:Green");
            this->setWin();
        }
        else
        {
            ui->t_result->setStyleSheet("background:Red;");
            this->setLose();
        }
        ui->computerButton->setEnabled(false);
        ui->playerButton->setEnabled(false);
        ui->b_ok->setEnabled(true);
    }
    }
}



void bookcricket::setWin()
{
    Minigame::setWin();

    ui->t_result->setText(QString("You Win!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

void bookcricket::setLose()
{
    Minigame::setLose();

    ui->t_result->setText(QString("You Lose!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

void bookcricket::quit()
{
    Minigame::quit();

    ui->b_ok->setEnabled(true);
}

void bookcricket::on_b_about_clicked()
{

    aboutbookcricket dialog(this);
    dialog.exec();
}

void bookcricket::on_b_ok_clicked()
{
    this->done(QDialog::Accepted);
}
