#include "minigame.h"

Minigame::Minigame()
{
    this->win = false;
}

Minigame::~Minigame()
{
}

bool Minigame::isWin()
{
    return this->win;
}

void Minigame::setLose()
{
    this->win = false;
}

void Minigame::setWin()
{
    this->win = true;
}

void Minigame::quit()
{
}
