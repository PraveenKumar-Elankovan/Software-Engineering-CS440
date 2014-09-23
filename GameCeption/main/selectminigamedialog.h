#ifndef SELECTMINIGAMEDIALOG_H
#define SELECTMINIGAMEDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class SelectMinigameDialog;
}

class SelectMinigameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectMinigameDialog(QWidget *parent = 0);
    ~SelectMinigameDialog();
    std::string getSelectedMinigame();

private slots:
    void on_b_ok_clicked();

    void on_c_minigames_currentTextChanged(const QString &arg1);

private:
    Ui::SelectMinigameDialog *ui;
    std::string selectedMinigame;
};

#endif // SELECTMINIGAMEDIALOG_H
