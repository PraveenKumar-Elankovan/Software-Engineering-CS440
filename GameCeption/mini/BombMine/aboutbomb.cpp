#include "aboutbomb.h"
#include "ui_aboutbomb.h"

aboutBomb::aboutBomb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutBomb)
{
    ui->setupUi(this);
}

aboutBomb::~aboutBomb()
{
    delete ui;
}

void aboutBomb::on_buttonBox_clicked()
{
    this->done(QDialog::Accepted);
}
