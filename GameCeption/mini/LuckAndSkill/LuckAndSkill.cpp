#include "mini/LuckAndSkill/luckandskill.h"
#include "ui_LuckAndSkill.h"
//#include "ui_mini1.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <QTimer>
using namespace std;

LuckAndSkill::LuckAndSkill(QWidget *parent) :
    QDialog(parent,  Qt::CustomizeWindowHint  | Qt::WindowTitleHint ),
    Minigame(),
    ui(new Ui::LuckAndSkill)
{
    ui->setupUi(this);
    ui->b_ok->setEnabled(false);
    ui->pushButton_2->setAlignment(Qt::AlignCenter);
    configureGame();
}

/****************
 * Clean all minigame code
 ****************/
LuckAndSkill::~LuckAndSkill()
{

    delete ui;
}

/******** PRIVATE **********/

/****************
 * Configure minigame
 ****************/
void LuckAndSkill::configureGame()
{
    this->canYouPlay = true;
    this->numberOfTimesStartWasPressed = 0;
    this->randomNumberYouGotToBeat = 0;
    //TODO - configure minigame to start
    int randomNumber = rand();
    randomNumber = randomNumber % 100;
    char buffer[3];
    this->randomNumberYouGotToBeat = randomNumber;
    sprintf(buffer, "%d", randomNumber);
    ui->pushButton->setText(buffer);
    ui->pushButton_2->setText("Get a number higher than the one above");
    //connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(generateRandomNumber()));
    connect(ui->StartButton, SIGNAL(clicked()), this, SLOT(startTimer()));
    connect(ui->StopButton, SIGNAL(clicked()), this, SLOT(stop()));

     //QTimer *timer = new QTimer(this);
    this->timer = new QTimer();
     connect(timer, SIGNAL(timeout()), this, SLOT(generateRandomNumber()));
}

void LuckAndSkill::startTimer(){
   if(this->canYouPlay == true){
    this->timer->start(500);
   }


}

void LuckAndSkill::generateRandomNumber(){
    int randomNumber = rand();
    randomNumber = randomNumber % 100;
    char buffer[3];
    sprintf(buffer, "%d", randomNumber);
    this->numberYouGot = randomNumber;
    ui->pushButton_2->setText(buffer);
    ui->pushButton_2->setAlignment(Qt::AlignCenter);

}

void LuckAndSkill::start(){
   // char buffer[3];
    //time_t datime;
    //time(&datime);
    //double originalTime = datime;
    //double incrementTime;
    //double differenceBetweenOriginalTimeAndIncrementTime = 0;


     //         this->random = rand() % 100;
       //     sprintf(buffer, "%d", this->random);
         //   ui->pushButton_2->setText(buffer);
           //  originalTime = incrementTime;





}

void LuckAndSkill::stop(){

    if(this->canYouPlay == true){

        ui->StopButton->setText("stop");
        this->timer->stop();
        ui->StartButton->setDisabled(true);
        ui->StopButton->setDisabled(true);
        if(randomNumberYouGotToBeat < numberYouGot){
            setWin();
            quit();
        }else{
          setLose();
          quit();
        }
        this->canYouPlay = false;
    }




}


void LuckAndSkill::disableGame()
{
    //TODO - disable all minigame features
}

/****************
 * Do not modify
 ****************/
void LuckAndSkill::setWin()
{
    Minigame::setWin();

    ui->t_result->setText(QString("You Win!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

/****************
 * Do not modify
 ****************/
void LuckAndSkill::setLose()
{
    Minigame::setLose();

    ui->t_result->setText(QString("You Lose!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

/****************
 * Do not modify
 ****************/
void LuckAndSkill::quit()
{
    Minigame::quit();

    disableGame();

    ui->b_ok->setEnabled(true);
}

/******** PRIVATE SLOTS **********/

/****************
 * Do not modify
 ****************/
void LuckAndSkill::on_b_ok_clicked()
{
    this->done(QDialog::Accepted);
}
