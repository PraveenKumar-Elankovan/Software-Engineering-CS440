#include "trivia.h"
#include "ui_trivia.h"

Trivia::Trivia(QWidget *parent) :
    QDialog(parent,  Qt::CustomizeWindowHint  | Qt::WindowTitleHint ),
    ui(new Ui::Trivia)
{
    ui->setupUi(this);
    ui->b_ok->setEnabled(false);

    configureGame();
}

/****************
 * Clean all minigame code
 ****************/
Trivia::~Trivia()
{
    delete ui;
}

/******** PRIVATE **********/

/****************
 * Configure minigame
 ****************/
void Trivia::configureGame()
{
    srand(time(0));
    this->question = rand() % numQuestions;

    ui->t_question->setText(QString(questions[question][0]));
    ui->t_question->setAlignment(Qt::AlignCenter);
}

void Trivia::disableGame()
{
    ui->b_false->setEnabled(false);
    ui->b_true->setEnabled(false);
}

/****************
 * Do not modify
 ****************/
void Trivia::setWin()
{
    Minigame::setWin();

    ui->t_result->setText(QString("Win!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

/****************
 * Do not modify
 ****************/
void Trivia::setLose()
{
    Minigame::setLose();

    ui->t_result->setText(QString("Lose!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

/****************
 * Do not modify
 ****************/
void Trivia::quit()
{
    Minigame::quit();

    disableGame();

    ui->b_ok->setEnabled(true);
}

/******** PRIVATE SLOTS **********/

/****************
 * Do not modify
 ****************/
void Trivia::on_b_ok_clicked()
{
    this->done(QDialog::Accepted);
}

void Trivia::on_b_false_clicked()
{
    if(strcmp(questions[this->question][1], "f") == 0)
    {
        setWin();
    }
    else
    {
        setLose();
    }
    quit();
}

void Trivia::on_b_true_clicked()
{
    if(strcmp(questions[this->question][1], "t") == 0)
    {
        setWin();
    }
    else
    {
        setLose();
    }
    quit();
}
