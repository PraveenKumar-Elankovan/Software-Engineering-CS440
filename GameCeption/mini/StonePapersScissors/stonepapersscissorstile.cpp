#include "mini/StonePapersScissors/stonepapersscissorstile.h"


StonePapersScissorsTile::StonePapersScissorsTile(int index, const char *a, QWidget* parent)
    :QPushButton(parent)
{
    this->index=index;
    this->a = a;
}
StonePapersScissorsTile::StonePapersScissorsTile(const char *a, QWidget* parent)
    :QPushButton(parent)
{

    this->a = a;
}

StonePapersScissorsTile::~StonePapersScissorsTile()
{

}

int StonePapersScissorsTile::getIndex()
{
    return this->index;
}
