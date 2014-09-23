#ifndef GAMEBOARDSIZEDIALOG_H
#define GAMEBOARDSIZEDIALOG_H

#include <QAbstractButton>
#include <QDialog>
#include "shared.h"

#define lowestBoardSize 3

namespace Ui {
class GameBoardSizeDialog;
}

class GameBoardSizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameBoardSizeDialog(QWidget *parent = 0);
    int board_size;
    ~GameBoardSizeDialog();

private slots:
    void on_c_boardsize_currentIndexChanged(int index);

    void on_b_ok_clicked();

private:
    Ui::GameBoardSizeDialog *ui;
};

#endif // GAMEBOARDSIZEDIALOG_H
