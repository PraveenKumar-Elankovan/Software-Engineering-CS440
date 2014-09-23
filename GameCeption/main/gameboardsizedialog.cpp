#include "gameboardsizedialog.h"
#include "ui_gameboardsizedialog.h"
#include "mainwindow.h"

GameBoardSizeDialog::GameBoardSizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameBoardSizeDialog)
{
    ui->setupUi(this);
    board_size = lowestBoardSize; //default
}

GameBoardSizeDialog::~GameBoardSizeDialog()
{
    delete ui;
}

void GameBoardSizeDialog::on_c_boardsize_currentIndexChanged(int index)
{
    board_size = index + lowestBoardSize; //shared.h
}

void GameBoardSizeDialog::on_b_ok_clicked()
{
    this->done(QDialog::Accepted);
}
