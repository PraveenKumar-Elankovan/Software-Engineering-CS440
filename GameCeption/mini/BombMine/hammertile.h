#ifndef HAMMERTILE_H
#define HAMMERTILE_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class hammertile;
}

class hammertile : public QPushButton
{
    Q_OBJECT

public:
    explicit hammertile(int row, int col, QWidget *parent = 0);
    void setValue(char c);
    int getRow() const;
    int getCol() const;
    char getValue();
    void setCol(int colomn);
    ~hammertile();

private:
    Ui::hammertile *ui;
    int row, col;
    char value;
};

#endif // HAMMERTILE_H
