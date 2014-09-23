#ifndef TRIVIA_H
#define TRIVIA_H

#include <QDialog>
#include <QAbstractButton>
#include "main/minigame.h"

namespace Ui {
class Trivia;
}

class Trivia : public QDialog, public Minigame
{
    Q_OBJECT

public:
    explicit Trivia(QWidget *parent = 0);
    ~Trivia();

private slots:
    void on_b_ok_clicked();

    void on_b_false_clicked();

    void on_b_true_clicked();

private:
    Ui::Trivia *ui;
    int question;

    const int numQuestions = 20;
    const char* questions[20][2] = {
        {"Electrons are larger than molecules.", "f"},
        {"The Atlantic Ocean is the biggest ocean on Earth.", "f"},
        {"The chemical make up food often changes when you cook it.", "t"},
        {"Sharks are mammals.", "f"},
        {"The human body has four lungs.", "f"},
        {"Atoms are most stable when their outer shells are full.", "t"},
        {"Filtration separates mixtures based upon their particle size.", "t"},
        {"Venus is the closest planet to the Sun.", "f"},
        {"Conductors have low resistance.", "t"},
        {"Molecules can have atoms from more than one chemical element.", "t"},
        {"Water is an example of a chemical element.", "f"},
        {"The study of plants is known as botany.", "t"},
        {"Mount Kilimanjaro is the tallest mountain in the world.", "f"},
        {"Floatation separates mixtures based on density.", "t"},
        {"Herbivores eat meat.", "f"},
        {"Atomic bombs work by atomic fission.", "t"},
        {"Molecules are chemically bonded.", "t"},
        {"Spiders have six legs.", "f"},
        {"Kelvin is a measure of temperature.", "t"},
        {"The human skeleton is made up of less than 100 bones.", "f"},
    };


    void configureGame();
    void disableGame();
    void setWin();
    void setLose();
    void quit();
};

#endif // TRIVIA_H
