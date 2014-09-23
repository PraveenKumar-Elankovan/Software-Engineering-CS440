#ifndef TILE_H
#define TILE_H

#include "shared.h"
#include <QPushButton>

class Tile : public QPushButton
{
    Q_OBJECT
public:
    Tile(int row, int col, QWidget* parent = 0);
    void handleClicked(int player);
    void setValue(char c);
    void setHighlight();
    int getRow() const;
    int getCol() const;
    int getState() const;
    char getValue();
    void setCol(int colomn);
    bool isEmpty();
private:
    Tile*** tile;
    int row, col, state;
    char value;
};

#endif // TILE_H
