#include "hammer.h"
#include "ui_hammer.h"
#include <stdlib.h>

hammer::hammer(QWidget *parent) :QDialog(parent, Qt::CustomizeWindowHint  | Qt::WindowTitleHint ),
    Minigame(),
    ui(new Ui::hammer)
{
    ui->setupUi(this);
    ui->b_ok->setEnabled(false);
    this->counter = 0;

    configureGame();
}

hammer::~hammer()
{

        delete ui;
}

void hammer::configureGame()
{
    tile = new hammertile**[num2];

    connect(ui->b_about, SIGNAL(clicked()), this, SLOT(on_b_about_clicked()));

    for(int i = 0; i < num2; i++)
        tile[i] = new hammertile*[num2];

    for(int row = 0; row < num2; row++) {
        for(int col = 0; col < num2; col++) {
            tile[row][col] = new hammertile(row, col, this);
            QSizePolicy policy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
            tile[row][col]->setSizePolicy(policy);
            connect(tile[row][col], SIGNAL(clicked()), this, SLOT(on_b_tile_clicked()));
            ui->g_board->addWidget(tile[row][col], row, col);
        }
    }
    for(int i = 0 ; i < num2; i++)
        for(int j = 0; j < num2; j++)
        {
            this->tile[i][j]->setText(QString(" "));
            this->tile[i][j]->setValue(' ');
        }
    this->disableGame();
    connect(ui->start, SIGNAL(clicked()), this, SLOT(startGame()));

}

void hammer::startGame()
{
    this->manipulate();

}

void hammer::manipulate()
{
    int ActRowNum, ActColNum;

    ui->start->setEnabled(false);

    for (int i = 0; i < 6; i++)
    {
        ActRowNum = rand() % num2;
        ActColNum = rand() % num2;

        this->tile[ActRowNum][ActColNum]->setValue('*');
    }

    for(int i = 0 ; i < num2; i++)
        for(int j = 0; j < num2; j++)
            this->tile[i][j]->setEnabled(true);

}

void hammer::on_b_tile_clicked()
{
    hammertile* button = (hammertile*)sender();
    char temp = '*';

    if (this->tile[button->getRow()][button->getCol()]->getValue() == temp)
    {
        this->setLose();
        button->setStyleSheet("background-color:Red;");
        ui->t_result->setStyleSheet("background:Red;");
    }
    else
    {
        this->setWin();
        button->setStyleSheet("background-color:Green;");
        ui->t_result->setStyleSheet("background:Green;");
    }
    this->disableGame();
    for(int i = 0 ; i < num2; i++)
        for(int j = 0; j < num2; j++)
        {
            char arr[] = {tile[i][j]->getValue(), '\0'};
            this->tile[i][j]->setText(QString(arr));
        }
    ui->b_ok->setEnabled(true);

}


void hammer::disableGame()
{

    for(int i = 0 ; i < num2; i++)
        for(int j = 0; j < num2; j++)
        {
            this->tile[i][j]->setEnabled(false);

        }
}


    void hammer::setWin()
{
    Minigame::setWin();

    ui->t_result->setText(QString("You Win!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

void hammer::setLose()
{
    Minigame::setLose();

    ui->t_result->setText(QString("You Lose!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

void hammer::quit()
{
    Minigame::quit();

    disableGame();

    ui->b_ok->setEnabled(true);
}

void hammer::on_b_ok_clicked()
{
    this->done(QDialog::Accepted);
}


void hammer::on_b_about_clicked()
{

    aboutBomb dialog(this);
    dialog.exec();
}
