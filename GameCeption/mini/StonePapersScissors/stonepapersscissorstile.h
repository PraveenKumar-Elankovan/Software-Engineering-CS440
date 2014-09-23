#ifndef STONEPAPERSSCISSORSTILE_H
#define STONEPAPERSSCISSORSTILE_H

#include <QPushButton>

class StonePapersScissorsTile : public QPushButton
{
    Q_OBJECT

public:
    explicit StonePapersScissorsTile(int index,const char* a, QWidget *parent = 0);
    explicit StonePapersScissorsTile(const char* a, QWidget *parent = 0);
    ~StonePapersScissorsTile();
    int getIndex();

private:
    const char* a;
    int index;
};

#endif // STONEPAPERSSCISSORSTILE_H
