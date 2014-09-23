#include "mini/StonePapersScissors/stonepapersscissors.h"
#include "ui_stonepapersscissors.h"
#include "math.h"
#include <stdlib.h>
const char* a[]={"Stone","Paper","Scissors",""};
char output[100];
/****************
 * Do not modify
 ****************/
StonePapersScissors::StonePapersScissors(QWidget *parent) :
    QDialog(parent, Qt::CustomizeWindowHint  | Qt::WindowTitleHint ),
    Minigame(),
    ui(new Ui::StonePapersScissors)
{
    strcpy(output,"");
    ui->setupUi(this);
    ui->t_result->setEnabled(false);

    ui->b_ok->setEnabled(false);
    configureGame();
}

/****************
 * Clean all minigame code
 ****************/
StonePapersScissors::~StonePapersScissors()
{
    for(int i = 0; i < num1; i++)
        delete this->tile[i];
    delete ui;
}

/******** PRIVATE **********/

/****************
 * Configure minigame
 ****************/
void StonePapersScissors::configureGame()
{

    srand(time(0));
    for(int index = 0; index < num1; index++)
    {
        tile[index] = new StonePapersScissorsTile(index, a[index], this);
        tile[index]->setText(QString(a[index]));
        tile[index]->setFixedSize(150, 150);
        connect(tile[index], SIGNAL(clicked()), this, SLOT(on_b_tile_clicked()));
        ui->g_grid->addWidget(tile[index], 0, index);
        configureAIGrid(3);
    }
}
void StonePapersScissors::configureAIGrid(int unique)
{

    srand(time(0));

        tileAI = new StonePapersScissorsTile(a[unique], this);
        tileAI->setText(QString(a[unique]));
        tileAI->setFixedSize(150, 150);
        ui->AI_Grid->addWidget(tileAI, 0, unique);
  }

void StonePapersScissors::disableGame()
{
    for(int i = 0; i < num1; i++)
        this->tile[i]->setEnabled(false);
}

/****************
 * Do not modify
 ****************/
void StonePapersScissors::setWin()
{
    Minigame::setWin();
     ui->t_result->setStyleSheet("background-color:Green;");
    ui->t_result->setText(QString(strcat(output,"You Win!!!")));
    ui->t_result->setAlignment(Qt::AlignCenter);

}

/****************
 * Do not modify
 ****************/
void StonePapersScissors::setLose()
{
    Minigame::setLose();
    ui->t_result->setStyleSheet("background-color:Red;");
    ui->t_result->setText(QString(strcat(output,"You Lose!!!")));

    ui->t_result->setAlignment(Qt::AlignCenter);
    }

/****************
 * Do not modify
 ****************/
void StonePapersScissors::quit()
{
    Minigame::quit();
    disableGame();
    ui->t_result->setEnabled(true);
    ui->b_ok->setEnabled(true);
}

/******** PRIVATE SLOTS **********/


/****************
 * Set win or lose
 ****************/
void StonePapersScissors::on_b_tile_clicked()
{

    StonePapersScissorsTile* tile = (StonePapersScissorsTile*)sender();
    tile->setStyleSheet("background-color:Grey;");
    int index;
    index=tile->getIndex();
     int flag=0;
     int unique;
     while(flag==0)
        {

       srand(time(0));
        unique = rand() % num1;
      if(index!=unique)
      {
          if((index == 0 && unique == 2) || (index == 1 && unique == 0) || (index == 2 && unique == 1))
          {

              setWin();
              flag=1;
          }
          else
          {

              setLose();
              flag=1;
          }
      }

     }
    configureAIGrid(unique);
    quit();


}



/****************
 * Do not modify
 ****************/
void StonePapersScissors::on_b_ok_clicked()
{
    this->done(QDialog::Accepted);
}

void StonePapersScissors::on_b_about_clicked()
{

    About_StonePapersScissors dialog(this);
    dialog.exec();
}
