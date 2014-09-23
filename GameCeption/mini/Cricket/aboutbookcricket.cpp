#include "aboutbookcricket.h"
#include "ui_aboutbookcricket.h"

aboutbookcricket::aboutbookcricket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutbookcricket)
{
    ui->setupUi(this);
}

aboutbookcricket::~aboutbookcricket()
{
    delete ui;
}

void aboutbookcricket::on_pushButton_clicked()
{
    this->done(QDialog::Accepted);
}
