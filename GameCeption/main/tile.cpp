#include "tile.h"

Tile::Tile(int row, int col, QWidget* parent)
    :QPushButton(parent)
{
    this->row = row;
    this->col = col;
    this->state = _empty;
    this->setText(QString(""));
}

bool Tile::isEmpty()
{
    return (this->state == _empty);
}

void Tile::handleClicked(int player)
{
    if( !this->isEmpty())
        return;

    this->state = player;
    if(player == _p1)
    {
        setValue('X');
    }
    else
    {
        setValue('O');
    }
}

void Tile::setValue(char c)
{
    if(c != 'X' && c != 'O')
        return;

    this->setText(QString(c));
    this->value=c;
}

void Tile::setHighlight()
{
    this->setStyleSheet("background-color:LightGrey;");
}

char Tile::getValue()
{
    return this->value;
}
int Tile::getRow() const
{
    return this->row;
}

int Tile::getCol() const
{
    return this->col;
}

int Tile::getState() const
{
    return this->state;
}
