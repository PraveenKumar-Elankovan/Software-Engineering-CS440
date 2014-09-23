#include "hammertile.h"
#include "ui_hammertile.h"

hammertile::hammertile(int row, int col, QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::hammertile)
{
    this->row = row;
    this->col = col;
    this->setText(QString(""));
}

hammertile::~hammertile()
{
    delete ui;
}

void hammertile::setValue(char c)
{
    this->value=c;
}


char hammertile::getValue()
{
    return this->value;
}
int hammertile::getRow() const
{
    return this->row;
}

int hammertile::getCol() const
{
    return this->col;
}


