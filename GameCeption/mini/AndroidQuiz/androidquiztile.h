#ifndef ANDROIDQUIZTILE_H
#define ANDROIDQUIZTILE_H
#include <QPushButton>

class AndroidQuizTile : public QPushButton
{
    Q_OBJECT

public:
    explicit AndroidQuizTile(int index,const char* a, QWidget *parent = 0);
    ~AndroidQuizTile();
    int getIndex();

private:
    const char* a;
    int index;
};

#endif // ANDROIDQUIZTILE_H

