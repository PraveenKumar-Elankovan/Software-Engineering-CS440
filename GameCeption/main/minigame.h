#ifndef DIALOG_H
#define DIALOG_H

class Minigame
{
public:
    Minigame();
    ~Minigame();
    bool isWin();
    void setWin();
    void setLose();
    void quit();

protected:
    bool win;
};

#endif // DIALOG_H
