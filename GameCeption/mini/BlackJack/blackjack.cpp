#include "mini/BlackJack/blackjack.h"
#include "ui_blackjack.h"
#include <stdlib.h>

const char* userCards[10]={"","","","","","","","","",""};
int usercards[10];
const char* AICards[10];
int AIcards[10];
const char* A3[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int numOfCards;
int hitDrawFlag=0;


BlackJack::BlackJack(QWidget *parent) :
    QDialog(parent, Qt::CustomizeWindowHint  | Qt::WindowTitleHint ),
    Minigame(),
    ui(new Ui::BlackJack)
{
    ui->setupUi(this);
    ui->b_ok->setDisabled(true);
      srand(time(0));
     for(int i=0;i<10;i++)
    {
        int randomNo=rand()%13;
        usercards[i]=randomNo+1;
        userCards[i]=A3[randomNo];
    }
        numOfCards=2;
        configureGame(2);
        srand(0);

        for(int i=0;i<10;i++)
    {
        int randomNo=usercards[rand()%13];
        AIcards[i]=randomNo+1;
        AICards[i]=A3[randomNo];
    }
       configureAIGame(1);
}


BlackJack::~BlackJack()
{

    delete ui;
}



void BlackJack::configureGame(int cardCount)
{

    srand(time(0));
    for(int index = 0; index < cardCount; index++)
    {
        tile[index] = new BlackJackTile(index, userCards[index], this);
        tile[index]->setText(QString(userCards[index]));
        tile[index]->setFixedSize(150, 150);
        tile[index]->setDisabled(true);
        ui->User_Grid->addWidget(tile[index], 0, index);


    }
}

void BlackJack::configureAIGame(int cardCount)
{
    srand(time(0));
    for(int index = 0; index < cardCount; index++)
    {
        tile[index] = new BlackJackTile(index, AICards[index], this);
        tile[index]->setText(QString(AICards[index]));
        tile[index]->setFixedSize(150, 150);
        tile[index]->setDisabled(true);

        ui->AI_Grid->addWidget(tile[index], 0, index);


    }
}


void BlackJack::setWin()
{
    Minigame::setWin();
    ui->label->setText("You Win !!!");
}


void BlackJack::setLose()
{
    Minigame::setLose();
    ui->label->setText("AI Win !!!");
}

void BlackJack::setBustAI()
{
    Minigame::setWin();
    configureAIGame(numOfCards);
    ui->label->setText("You Win !!! AI Busted");

}
void BlackJack::setBustUser()
{
    Minigame::setLose();
    ui->label->setText("You got Busted. AI Win !!!");
}
void BlackJack::quit()
{
    Minigame::quit();
    ui->b_ok->setEnabled(true);
    ui->Hit_Button->setDisabled(true);
    ui->Draw_Button->setDisabled(true);
}

/******** PRIVATE SLOTS **********/


/****************
 * Set win or lose
 ****************/


void BlackJack::on_Hit_Button_clicked()
{
    if(hitDrawFlag==0)
        configureAIGame(numOfCards);
    int playerSum=0;
    int AISum=0;
    for (int i=0;i<numOfCards;i++)
    {
        if(usercards[i]==11 || usercards[i]==12 || usercards[i]==13)
            playerSum+=10;
        else
            playerSum+=usercards[i];
        if(AIcards[i]==11 || AIcards[i]==12 || AIcards[i]==13)
            AISum+=10;
        else
            AISum+=AIcards[i];
    }
    if(playerSum>20)
       {
        setBustUser();
        quit();
        }
  if(AISum>20 && playerSum<=20)
  {
      setBustAI();
      quit();
  }
  if(AISum==playerSum && hitDrawFlag==0)
  {
      ui->label->setText("Push and so The Player Wins");
      Minigame::setWin();
      configureAIGame(numOfCards);
      quit();
  }
  if(playerSum <=20 && AISum<=20 && playerSum>AISum && hitDrawFlag==0)
        {
        setWin();
        quit();
        }
  if(AISum<=20 && playerSum<=20 && AISum>playerSum && hitDrawFlag==0)
        {
        setLose();
        quit();
        }
}
void BlackJack::on_Draw_Button_clicked()
{
    numOfCards++;
    configureGame(numOfCards);
    hitDrawFlag=1;
    on_Hit_Button_clicked();
    hitDrawFlag=0;

}
void BlackJack::on_b_about_clicked()
{

    About_BlackJack dialog(this);
    dialog.exec();
}
void BlackJack::on_b_ok_clicked()
{
    this->done(QDialog::Accepted);
}
