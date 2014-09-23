#include "about_blackjack.h"
#include "ui_about_blackjack.h"

About_BlackJack::About_BlackJack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About_BlackJack)
{
    ui->setupUi(this);
}

About_BlackJack::~About_BlackJack()
{
    delete ui;
}

void About_BlackJack::on_buttonBox_clicked()
{
    this->done(QDialog::Accepted);
}
