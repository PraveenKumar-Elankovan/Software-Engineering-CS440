
#include "mini/AndroidQuiz/androidquiztile.h"


AndroidQuizTile::AndroidQuizTile(int index, const char *a, QWidget* parent)
    :QPushButton(parent)
{
    this->index=index;
    this->a = a;
}
AndroidQuizTile::~AndroidQuizTile()
{

}

int AndroidQuizTile::getIndex()
{
    return this->index;
}
