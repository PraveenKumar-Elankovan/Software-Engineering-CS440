#ifndef BLACKJACKTILE_H
#define BLACKJACKTILE_H


#include <QPushButton>

class BlackJackTile : public QPushButton
{
    Q_OBJECT

public:
    explicit BlackJackTile(int index,const char* a, QWidget *parent = 0);

    ~BlackJackTile();
    int getIndex();

private:
    const char* a;
    int index;
};


#endif // BLACKJACKTILE_H
