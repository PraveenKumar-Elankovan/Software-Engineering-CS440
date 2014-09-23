//#include "mini/LuckAndSkill/luckandskill.h"
//#include "ui_LuckAndSkill.h"
//#include "ui_mini1.h"
#include "mini/WhackMole/WhackMole.h"
#include "ui_WhackMole.h"
//#include "ui"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <QTimer>
#include <unistd.h>
using namespace std;

WhackMole::WhackMole(QWidget *parent) :
    QDialog(parent,  Qt::CustomizeWindowHint  | Qt::WindowTitleHint ),
    Minigame(),
    ui(new Ui::WhackMole)
{
    ui->setupUi(this);
    ui->b_ok->setEnabled(false);
    //ui->pushButton_2->setAlignment(Qt::AlignCenter);
    configureGame();
}

/****************
 * Clean all minigame code
 ****************/
WhackMole::~WhackMole()
{

    delete ui;
}

/******** PRIVATE **********/

/****************
 * Configure minigame
 ****************/
void WhackMole::configureGame()
{
    this->numberOfMolesToHit = 7;
    this->numberOfMolesShown = 0;
    this->numberOfMolesThatHaveBeenHit = 0;
    this->timer = new QTimer();
    connect(ui->beatMoles, SIGNAL(clicked()), this, SLOT(startTheGame()));
    connect(timer, SIGNAL(timeout()), this, SLOT(visibleMole()));
    whiteTheButtons();
}

void WhackMole::whiteTheButtons(){
    ui->pushButton->setStyleSheet("background-color: white");
    ui->pushButton_2->setStyleSheet("background-color: white");
    ui->pushButton_3->setStyleSheet("background-color: white");
    ui->pushButton_4->setStyleSheet("background-color: white");
    ui->pushButton_5->setStyleSheet("background-color: white");
    ui->pushButton_6->setStyleSheet("background-color: white");

}

void WhackMole::disconnectAllButtons(){
    disconnect(ui->pushButton, SIGNAL(clicked()), this, SLOT(moleWasHit()));
    disconnect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(moleWasHit()));
    disconnect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(moleWasHit()));
    disconnect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(moleWasHit()));
    disconnect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(moleWasHit()));
    disconnect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(moleWasHit()));

}

void WhackMole::moleWasHit(){
    numberOfMolesThatHaveBeenHit++;
    string text = to_string(numberOfMolesThatHaveBeenHit);
    QString temp = QString::fromStdString(text);
    ui->lineEdit->setText(temp);
}

void WhackMole::visibleMole(){
    //resets the button image
    whiteTheButtons();
    //disconnects all signals from the mole holes
    disconnectAllButtons();
    //usleep(1000000);

    if(numberOfMolesShown < 15){
        this->whichMoleIsShowing = rand() % 6;
        //change the picture based on the number received;
        if(whichMoleIsShowing == 0){
            ui->pushButton->setStyleSheet("background-color: brown");
            connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(moleWasHit()));
        }
        if(whichMoleIsShowing == 1){
            ui->pushButton_2->setStyleSheet("background-color: brown");
            connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(moleWasHit()));
        }
        if(whichMoleIsShowing == 2){
            ui->pushButton_3->setStyleSheet("background-color: brown");
            connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(moleWasHit()));
        }
        if(whichMoleIsShowing == 3){
            ui->pushButton_4->setStyleSheet("background-color: brown");
            connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(moleWasHit()));
        }
        if(whichMoleIsShowing == 4){
            ui->pushButton_5->setStyleSheet("background-color: brown");
            connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(moleWasHit()));
        }
        if(whichMoleIsShowing == 5){
            ui->pushButton_6->setStyleSheet("background-color: brown");
            connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(moleWasHit()));
        }
        cout << "which moles " << whichMoleIsShowing << "\n";
        numberOfMolesShown++;
    }else{
        this->timer->stop();
        checkNumberOfMolesHit();
    }



}

void WhackMole::checkNumberOfMolesHit(){
    if(numberOfMolesThatHaveBeenHit >= numberOfMolesToHit){
        setWin();
        quit();
    }else{
        setLose();
        quit();
    }
    cout << "number of moles hit " << numberOfMolesThatHaveBeenHit << "\n";
}

void WhackMole::startTheGame(){
    this->timer->start(600);
}


void WhackMole::disableGame()
{
    //TODO - disable all minigame features
}

/****************
 * Do not modify
 ****************/
void WhackMole::setWin()
{
    Minigame::setWin();

    ui->t_result->setText(QString("You Win!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

/****************
 * Do not modify
 ****************/
void WhackMole::setLose()
{
    Minigame::setLose();

    ui->t_result->setText(QString("You Lose!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

/****************
 * Do not modify
 ****************/
void WhackMole::quit()
{
    Minigame::quit();

    disableGame();

    ui->b_ok->setEnabled(true);
}

/******** PRIVATE SLOTS **********/

/****************
 * Do not modify
 ****************/
void WhackMole::on_b_ok_clicked()
{
    this->done(QDialog::Accepted);
}
