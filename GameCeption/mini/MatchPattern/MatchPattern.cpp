//#include "mini1.h"
#include "mini/MatchPattern/MatchPattern.h"
//#include "ui_mini1.h"
#include "ui_MatchPattern.h"

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <QString>
using namespace std;

MatchPattern::MatchPattern(QWidget *parent) :
    QDialog(parent,  Qt::CustomizeWindowHint  | Qt::WindowTitleHint ),
    ui(new Ui::MatchPattern)
{
    ui->setupUi(this);
    ui->b_ok->setEnabled(false);

    configureGame();
}

/****************
 * Clean all minigame code
 ****************/
MatchPattern::~MatchPattern()
{
    delete ui;
}

/******** PRIVATE **********/

/****************
 * Configure minigame
 ****************/
void MatchPattern::configureGame()
{
    //TODO - configure minigame to start
    //generate random number pattern
    //int pattern[6];
    flashTheSquare = true;
    isPatternInitialized = false;
    squareToFlash = 0;
    int temp;
    for(int i = 0; i < 6; i++){
        temp = rand() % 8;
        pattern[i] = temp;
    }
    ui->pushButton->setStyleSheet("background-color: grey");
    ui->pushButton_2->setStyleSheet("background-color: grey");
    ui->pushButton_3->setStyleSheet("background-color: grey");
    ui->pushButton_4->setStyleSheet("background-color: grey");
    ui->pushButton_5->setStyleSheet("background-color: grey");
    ui->pushButton_6->setStyleSheet("background-color: grey");
    ui->pushButton_7->setStyleSheet("background-color: grey");
    ui->pushButton_8->setStyleSheet("background-color: grey");

    this->timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(showPattern()));
    //connect(ui->quit, SIGNAL(clicked()), this, SLOT(myquit()));
    connect(ui->clockButton, SIGNAL(clicked()), this, SLOT(startClock()));


//    string s = to_string(pattern[0]);

//    for(int i = 1; i < 6; i++){
//        s.append(to_string(pattern[i]));

//    }
//    QString ss = QString::fromStdString(s);
//    ui->pushButton_9->setText(ss);

    this->indexInThePattern = 0;
    //connec the signals to buttons;
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(sendNumFromButton1()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(sendNumFromButton2()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(sendNumFromButton3()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(sendNumFromButton4()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(sendNumFromButton5()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(sendNumFromButton6()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(sendNumFromButton7()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(sendNumFromButton8()));
}

void MatchPattern::startClock(){
    this->timer->start(1000);
}

void MatchPattern::checkForWin(){
    bool doThePatternsMatch = true;
    for(int i = 0; i < 6; i++){
        if(pattern[i] != patternReceivedFromPlayer[i]){
            doThePatternsMatch = false;
        }
    }
//    cout << "\n";
//    for(int i = 0; i < 6; i++){
//        cout << pattern[i];
//    }
//    cout << "\n";
//    for(int i = 0; i < 6; i++){
//        cout << patternReceivedFromPlayer[i];
//    }cout  << "\n";

    if(doThePatternsMatch == true){
        setWin();
        quit();
    }else if(doThePatternsMatch == false){
        setLose();
        quit();
    }
}

void MatchPattern::sendNumFromButton1(){

    if(isPatternInitialized == true){
        if(indexInThePattern < 5){
            patternReceivedFromPlayer[indexInThePattern] = 0;
            indexInThePattern++;
        }else{
            patternReceivedFromPlayer[indexInThePattern] = 0;
            checkForWin();
        }
    }

}

void MatchPattern::sendNumFromButton2(){
    if(isPatternInitialized == true){
        if(indexInThePattern < 5){
            patternReceivedFromPlayer[indexInThePattern] = 1;
            indexInThePattern++;
        }else{
            patternReceivedFromPlayer[indexInThePattern] = 1;
            checkForWin();
        }
    }

}

void MatchPattern::sendNumFromButton3(){
    if(isPatternInitialized == true){
        if(indexInThePattern < 5){
            patternReceivedFromPlayer[indexInThePattern] = 2;
            indexInThePattern++;
        }else{
            patternReceivedFromPlayer[indexInThePattern] = 2;
            checkForWin();
        }
    }

}

void MatchPattern::sendNumFromButton4(){
    if(isPatternInitialized == true){
        if(indexInThePattern < 5){
            patternReceivedFromPlayer[indexInThePattern] = 3;
            indexInThePattern++;
        }else{
            patternReceivedFromPlayer[indexInThePattern] = 3;
            checkForWin();
        }
    }

}

void MatchPattern::sendNumFromButton5(){
    if(isPatternInitialized == true){
        if(indexInThePattern < 5){
            patternReceivedFromPlayer[indexInThePattern] = 4;
            indexInThePattern++;
        }else{
            patternReceivedFromPlayer[indexInThePattern] = 4;
            checkForWin();
        }
    }

}

void MatchPattern::sendNumFromButton6(){
    if(isPatternInitialized == true){
        if(indexInThePattern < 5){
            patternReceivedFromPlayer[indexInThePattern] = 5;
            indexInThePattern++;
        }else{
            patternReceivedFromPlayer[indexInThePattern] = 5;
            checkForWin();
        }
    }

}

void MatchPattern::sendNumFromButton7(){
    if(isPatternInitialized == true){
        if(indexInThePattern < 5){
            patternReceivedFromPlayer[indexInThePattern] = 6;
            indexInThePattern++;
        }else{
            patternReceivedFromPlayer[indexInThePattern] = 6;
            checkForWin();
        }
    }

}

void MatchPattern::sendNumFromButton8(){
    if(isPatternInitialized == true){
        if(indexInThePattern < 5){
            patternReceivedFromPlayer[indexInThePattern] = 7;
            indexInThePattern++;
        }else{
            patternReceivedFromPlayer[indexInThePattern] = 7;
            checkForWin();
        }
    }

}
//now flash the squares the pattern
void MatchPattern::showPattern(){

    //checks square to flash which corresponds to the first
    //number in the pattern array
    if(squareToFlash == 6){
        this->timer->stop();
        this->isPatternInitialized = true;
    }

    if(flashTheSquare == true){
        if(squareToFlash == 0)
        {
            if(pattern[0] == 0){
                ui->pushButton->setStyleSheet("background-color: red");
            }
            if(pattern[0] == 1){
                ui->pushButton_2->setStyleSheet("background-color: red");
            }
            if(pattern[0] == 2){
                ui->pushButton_3->setStyleSheet("background-color: red");
            }
            if(pattern[0] == 3){
                ui->pushButton_4->setStyleSheet("background-color: red");
            }
            if(pattern[0] == 4){
                ui->pushButton_5->setStyleSheet("background-color: red");
            }
            if(pattern[0] == 5){
                ui->pushButton_6->setStyleSheet("background-color: red");
            }
            if(pattern[0] == 6){
                ui->pushButton_7->setStyleSheet("background-color: red");
            }
            if(pattern[0] == 7){
                ui->pushButton_8->setStyleSheet("background-color: red");
            }
//            string s = to_string(pattern[0]);
//            QString ss = QString::fromStdString(s);
//            ui->numBox->setText(ss);
        }
        if(squareToFlash == 1)
        {
            if(pattern[1] == 0){
                ui->pushButton->setStyleSheet("background-color: red");
            }
            if(pattern[1] == 1){
                ui->pushButton_2->setStyleSheet("background-color: red");
            }
            if(pattern[1] == 2){
                ui->pushButton_3->setStyleSheet("background-color: red");
            }
            if(pattern[1] == 3){
                ui->pushButton_4->setStyleSheet("background-color: red");
            }
            if(pattern[1] == 4){
                ui->pushButton_5->setStyleSheet("background-color: red");
            }
            if(pattern[1] == 5){
                ui->pushButton_6->setStyleSheet("background-color: red");
            }
            if(pattern[1] == 6){
                ui->pushButton_7->setStyleSheet("background-color: red");
            }
            if(pattern[1] == 7){
                ui->pushButton_8->setStyleSheet("background-color: red");
            }
//            string s = to_string(pattern[1]);
//            QString ss = QString::fromStdString(s);
//            ui->numBox->setText(ss);
        }
        if(squareToFlash == 2)
        {
            if(pattern[2] == 0){
                ui->pushButton->setStyleSheet("background-color: red");
            }
            if(pattern[2] == 1){
                ui->pushButton_2->setStyleSheet("background-color: red");
            }
            if(pattern[2] == 2){
                ui->pushButton_3->setStyleSheet("background-color: red");
            }
            if(pattern[2] == 3){
                ui->pushButton_4->setStyleSheet("background-color: red");
            }
            if(pattern[2] == 4){
                ui->pushButton_5->setStyleSheet("background-color: red");
            }
            if(pattern[2] == 5){
                ui->pushButton_6->setStyleSheet("background-color: red");
            }
            if(pattern[2] == 6){
                ui->pushButton_7->setStyleSheet("background-color: red");
            }
            if(pattern[2] == 7){
                ui->pushButton_8->setStyleSheet("background-color: red");
            }
//            string s = to_string(pattern[2]);
//            QString ss = QString::fromStdString(s);
//            ui->numBox->setText(ss);
        }
        if(squareToFlash == 3)
        {
            if(pattern[3] == 0){
                ui->pushButton->setStyleSheet("background-color: red");
            }
            if(pattern[3] == 1){
                ui->pushButton_2->setStyleSheet("background-color: red");
            }
            if(pattern[3] == 2){
                ui->pushButton_3->setStyleSheet("background-color: red");
            }
            if(pattern[3] == 3){
                ui->pushButton_4->setStyleSheet("background-color: red");
            }
            if(pattern[3] == 4){
                ui->pushButton_5->setStyleSheet("background-color: red");
            }
            if(pattern[3] == 5){
                ui->pushButton_6->setStyleSheet("background-color: red");
            }
            if(pattern[3] == 6){
                ui->pushButton_7->setStyleSheet("background-color: red");
            }
            if(pattern[3] == 7){
                ui->pushButton_8->setStyleSheet("background-color: red");
            }
//            string s = to_string(pattern[3]);
//            QString ss = QString::fromStdString(s);
//            ui->numBox->setText(ss);
        }if(squareToFlash == 4)
        {
            if(pattern[4] == 0){
                ui->pushButton->setStyleSheet("background-color: red");
            }
            if(pattern[4] == 1){
                ui->pushButton_2->setStyleSheet("background-color: red");
            }
            if(pattern[4] == 2){
                ui->pushButton_3->setStyleSheet("background-color: red");
            }
            if(pattern[4] == 3){
                ui->pushButton_4->setStyleSheet("background-color: red");
            }
            if(pattern[4] == 4){
                ui->pushButton_5->setStyleSheet("background-color: red");
            }
            if(pattern[4] == 5){
                ui->pushButton_6->setStyleSheet("background-color: red");
            }
            if(pattern[4] == 6){
                ui->pushButton_7->setStyleSheet("background-color: red");
            }
            if(pattern[4] == 7){
                ui->pushButton_8->setStyleSheet("background-color: red");
            }
//            string s = to_string(pattern[4]);
//            QString ss = QString::fromStdString(s);
//            ui->numBox->setText(ss);
        }
        if(squareToFlash == 5)
        {
            if(pattern[5] == 0){
                ui->pushButton->setStyleSheet("background-color: red");
            }
            if(pattern[5] == 1){
                ui->pushButton_2->setStyleSheet("background-color: red");
            }
            if(pattern[5] == 2){
                ui->pushButton_3->setStyleSheet("background-color: red");
            }
            if(pattern[5] == 3){
                ui->pushButton_4->setStyleSheet("background-color: red");
            }
            if(pattern[5] == 4){
                ui->pushButton_5->setStyleSheet("background-color: red");
            }
            if(pattern[5] == 5){
                ui->pushButton_6->setStyleSheet("background-color: red");
            }
            if(pattern[5] == 6){
                ui->pushButton_7->setStyleSheet("background-color: red");
            }
            if(pattern[5] == 7){
                ui->pushButton_8->setStyleSheet("background-color: red");
            }
//            string s = to_string(pattern[5]);
//            QString ss = QString::fromStdString(s);
//            ui->numBox->setText(ss);
        }
        //squareToFlash++;
        flashTheSquare = false;
    }else if(flashTheSquare == false){
        //reset the color of the square to original grey
        if(squareToFlash == 0)
        {
            if(pattern[0] == 0){
                ui->pushButton->setStyleSheet("background-color: grey");
            }
            if(pattern[0] == 1){
                ui->pushButton_2->setStyleSheet("background-color: grey");
            }
            if(pattern[0] == 2){
                ui->pushButton_3->setStyleSheet("background-color: grey");
            }
            if(pattern[0] == 3){
                ui->pushButton_4->setStyleSheet("background-color: grey");
            }
            if(pattern[0] == 4){
                ui->pushButton_5->setStyleSheet("background-color: grey");
            }
            if(pattern[0] == 5){
                ui->pushButton_6->setStyleSheet("background-color: grey");
            }
            if(pattern[0] == 6){
                ui->pushButton_7->setStyleSheet("background-color: grey");
            }
            if(pattern[0] == 7){
                ui->pushButton_8->setStyleSheet("background-color: grey");
            }
        }

        if(squareToFlash == 1)
        {
            if(pattern[1] == 0){
                ui->pushButton->setStyleSheet("background-color: grey");
            }
            if(pattern[1] == 1){
                ui->pushButton_2->setStyleSheet("background-color: grey");
            }
            if(pattern[1] == 2){
                ui->pushButton_3->setStyleSheet("background-color: grey");
            }
            if(pattern[1] == 3){
                ui->pushButton_4->setStyleSheet("background-color: grey");
            }
            if(pattern[1] == 4){
                ui->pushButton_5->setStyleSheet("background-color: grey");
            }
            if(pattern[1] == 5){
                ui->pushButton_6->setStyleSheet("background-color: grey");
            }
            if(pattern[1] == 6){
                ui->pushButton_7->setStyleSheet("background-color: grey");
            }
            if(pattern[1] == 7){
                ui->pushButton_8->setStyleSheet("background-color: grey");
            }
        }

        if(squareToFlash == 2)
        {
            if(pattern[2] == 0){
                ui->pushButton->setStyleSheet("background-color: grey");
            }
            if(pattern[2] == 1){
                ui->pushButton_2->setStyleSheet("background-color: grey");
            }
            if(pattern[2] == 2){
                ui->pushButton_3->setStyleSheet("background-color: grey");
            }
            if(pattern[2] == 3){
                ui->pushButton_4->setStyleSheet("background-color: grey");
            }
            if(pattern[2] == 4){
                ui->pushButton_5->setStyleSheet("background-color: grey");
            }
            if(pattern[2] == 5){
                ui->pushButton_6->setStyleSheet("background-color: grey");
            }
            if(pattern[2] == 6){
                ui->pushButton_7->setStyleSheet("background-color: grey");
            }
            if(pattern[2] == 7){
                ui->pushButton_8->setStyleSheet("background-color: grey");
            }
        }

        if(squareToFlash == 3)
        {
            if(pattern[3] == 0){
                ui->pushButton->setStyleSheet("background-color: grey");
            }
            if(pattern[3] == 1){
                ui->pushButton_2->setStyleSheet("background-color: grey");
            }
            if(pattern[3] == 2){
                ui->pushButton_3->setStyleSheet("background-color: grey");
            }
            if(pattern[3] == 3){
                ui->pushButton_4->setStyleSheet("background-color: grey");
            }
            if(pattern[3] == 4){
                ui->pushButton_5->setStyleSheet("background-color: grey");
            }
            if(pattern[3] == 5){
                ui->pushButton_6->setStyleSheet("background-color: grey");
            }
            if(pattern[3] == 6){
                ui->pushButton_7->setStyleSheet("background-color: grey");
            }
            if(pattern[3] == 7){
                ui->pushButton_8->setStyleSheet("background-color: grey");
            }
        }

        if(squareToFlash == 4)
        {
            if(pattern[4] == 0){
                ui->pushButton->setStyleSheet("background-color: grey");
            }
            if(pattern[4] == 1){
                ui->pushButton_2->setStyleSheet("background-color: grey");
            }
            if(pattern[4] == 2){
                ui->pushButton_3->setStyleSheet("background-color: grey");
            }
            if(pattern[4] == 3){
                ui->pushButton_4->setStyleSheet("background-color: grey");
            }
            if(pattern[4] == 4){
                ui->pushButton_5->setStyleSheet("background-color: grey");
            }
            if(pattern[4] == 5){
                ui->pushButton_6->setStyleSheet("background-color: grey");
            }
            if(pattern[4] == 6){
                ui->pushButton_7->setStyleSheet("background-color: grey");
            }
            if(pattern[4] == 7){
                ui->pushButton_8->setStyleSheet("background-color: grey");
            }
        }

        if(squareToFlash == 5)
        {
            if(pattern[5] == 0){
                ui->pushButton->setStyleSheet("background-color: grey");
            }
            if(pattern[5] == 1){
                ui->pushButton_2->setStyleSheet("background-color: grey");
            }
            if(pattern[5] == 2){
                ui->pushButton_3->setStyleSheet("background-color: grey");
            }
            if(pattern[5] == 3){
                ui->pushButton_4->setStyleSheet("background-color: grey");
            }
            if(pattern[5] == 4){
                ui->pushButton_5->setStyleSheet("background-color: grey");
            }
            if(pattern[5] == 5){
                ui->pushButton_6->setStyleSheet("background-color: grey");
            }
            if(pattern[5] == 6){
                ui->pushButton_7->setStyleSheet("background-color: grey");
            }
            if(pattern[5] == 7){
                ui->pushButton_8->setStyleSheet("background-color: grey");
            }
        }

        //increment pattern by one and reset the bool value to true
        squareToFlash++;
        flashTheSquare = true;
    }

}

void MatchPattern::myquit(){
    setWin();
    quit();

}

void MatchPattern::disableGame()
{
    //TODO - disable all minigame features
}

/****************
 * Do not modify
 ****************/
void MatchPattern::setWin()
{
    Minigame::setWin();

    ui->t_result->setText(QString("Win!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

/****************
 * Do not modify
 ****************/
void MatchPattern::setLose()
{
    Minigame::setLose();

    ui->t_result->setText(QString("Lose!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

/****************
 * Do not modify
 ****************/
void MatchPattern::quit()
{
    Minigame::quit();
    ui->clockButton->setDisabled(true);
    disableGame();

    ui->b_ok->setEnabled(true);
}

/******** PRIVATE SLOTS **********/

/****************
 * Do not modify
 ****************/
void MatchPattern::on_b_ok_clicked()
{
    quit();
    this->done(QDialog::Accepted);
}
