#include "mini/BlackJack/blackjacktile.h"


BlackJackTile::BlackJackTile(int index, const char *a, QWidget* parent)
    :QPushButton(parent)
{
    this->index=index;
    this->a = a;
}

BlackJackTile::~BlackJackTile()
{

}

int BlackJackTile::getIndex()
{
    return this->index;
}

