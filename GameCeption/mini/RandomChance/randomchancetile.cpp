#include "mini/RandomChance/randomchancetile.h"

RandomChanceTile::RandomChanceTile(int number, bool unique, QWidget* parent)
    :QPushButton(parent)
{
    this->number = number;
    this->unique = unique;
}

RandomChanceTile::~RandomChanceTile()
{

}

bool RandomChanceTile::getUnique()
{
    if(this->unique)
        return true;
    return false;
}
