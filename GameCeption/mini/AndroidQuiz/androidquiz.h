#ifndef ANDROIDQUIZ_H
#define ANDROIDQUIZ_H
#include "main/minigame.h"
#include "mini/AndroidQuiz/androidquiztile.h"
#include <QDialog>
#include <QAbstractButton>
#include <QDialog>
#define num3 4

namespace Ui {
class AndroidQuiz;
}

class AndroidQuiz : public QDialog, public Minigame
{
    Q_OBJECT

public:
    explicit AndroidQuiz(QWidget *parent = 0);
    ~AndroidQuiz();


private slots:
    void on_b_tile_clicked();
    void on_b_ok_clicked();

private:
    Ui::AndroidQuiz *ui;
    AndroidQuizTile* tile[num3];
    void configureGame(const char *a[]);
    void disableGame();
    void setWin();
    void setLose();
    void quit();

};

#endif // ANDROIDQUIZ_H
