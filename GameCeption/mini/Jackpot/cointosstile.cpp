#include "cointosstile.h"

CointossTile::CointossTile(int number, bool unique, QWidget* parent)
    :QPushButton(parent)
{
    this->number = number;
    this->unique = unique;
}

CointossTile::~CointossTile()
{

}

bool CointossTile::getUnique()
{
    if(this->unique)
        return true;
    return false;
}
