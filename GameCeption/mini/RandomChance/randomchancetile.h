#ifndef RANDOMCHANCETILE_H
#define RANDOMCHANCETILE_H

#include <QPushButton>

class RandomChanceTile : public QPushButton
{
    Q_OBJECT

public:
    explicit RandomChanceTile(int number, bool unique, QWidget *parent = 0);
    ~RandomChanceTile();
    bool getUnique();

private:
    int number;
    bool unique;
};

#endif // RANDOMCHANCETILE_H
