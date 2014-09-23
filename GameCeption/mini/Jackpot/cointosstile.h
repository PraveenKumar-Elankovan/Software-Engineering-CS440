#ifndef COINTOSSTILE_H
#define COINTOSSTILE_H

#include <QPushButton>

class CointossTile : public QPushButton
{
    Q_OBJECT

public:
    explicit CointossTile(int number, bool unique, QWidget *parent = 0);
    ~CointossTile();
    bool getUnique();

private:
    int number;
    bool unique;
};

#endif // COINTOSSTILE_H
