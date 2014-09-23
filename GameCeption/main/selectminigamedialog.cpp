#include "selectminigamedialog.h"
#include "ui_selectminigamedialog.h"

SelectMinigameDialog::SelectMinigameDialog(QWidget *parent) :
    QDialog(parent,  Qt::CustomizeWindowHint  | Qt::WindowTitleHint ),
    ui(new Ui::SelectMinigameDialog)
{
    ui->setupUi(this);
    this->selectedMinigame = "Random Chance"; //default mini
}

SelectMinigameDialog::~SelectMinigameDialog()
{
    delete ui;
}

void SelectMinigameDialog::on_b_ok_clicked()
{
    this->done(QDialog::Accepted);
}

void SelectMinigameDialog::on_c_minigames_currentTextChanged(const QString &arg1)
{
    this->selectedMinigame = arg1.toStdString();
}

std::string SelectMinigameDialog::getSelectedMinigame()
{
    return this->selectedMinigame;
}
