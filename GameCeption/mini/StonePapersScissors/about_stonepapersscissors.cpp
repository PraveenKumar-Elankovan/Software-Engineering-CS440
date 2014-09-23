#include "about_stonepapersscissors.h"
#include "ui_about_stonepapersscissors.h"

About_StonePapersScissors::About_StonePapersScissors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About_StonePapersScissors)
{
    ui->setupUi(this);
}

About_StonePapersScissors::~About_StonePapersScissors()
{
    delete ui;
}
void About_StonePapersScissors::on_buttonBox_clicked()
{
    this->done(QDialog::Accepted);
}
