#include "mainwindow.h"

/**** PUBLIC FUNCTIONS ***/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->JackpotLabel->setStyleSheet("Background-image: url(:/Images/jackpot.jpg);");
    ui->stackedWidget->setCurrentWidget(ui->w_main);
    this->player_turn = _p1;
    this->size = 0;
    this->flagAI=0;
}
MainWindow::~MainWindow()
{
    delete ui;
}


/**** PRIVATE FUNCTIONS ****/


void MainWindow::configureBoard()
{
    GameBoardSizeDialog* dialog = new GameBoardSizeDialog(this);
    dialog->exec();  //board size now set in shared.h
    board_size = dialog->board_size;
    tile = new Tile**[board_size];
    for(int i = 0; i < board_size; i++)
        tile[i] = new Tile*[board_size];
    this->size = 0;

    for(int row = 0; row < board_size; row++) {
        for(int col = 0; col < board_size; col++) {
            tile[row][col] = new Tile(row, col, this);
            QSizePolicy policy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
            tile[row][col]->setSizePolicy(policy);
            connect(tile[row][col], SIGNAL(clicked()), this, SLOT(on_b_tile_clicked()));
            ui->g_board->addWidget(tile[row][col], row, col);
        }
    }

    ui->t_result->setText(QString("Player 'X' Turn"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

void MainWindow::togglePlayer()
{
    if(player_turn == _p1) {
        player_turn = _p2;
        ui->t_result->setText(QString("Player 'O' Turn"));
    }
    else {
        player_turn = _p1;
        ui->t_result->setText(QString("Player 'X' Turn"));
    }

    ui->t_result->setAlignment(Qt::AlignCenter);
}

void MainWindow::disableTileClicks()
{
    for(int i=0;i<board_size;i++)
        for(int j=0;j<board_size;j++)
            tile[i][j]->setEnabled(false);
}

bool MainWindow::playMini()
{
    SelectMinigameDialog selectMinigameDialog(this);
    selectMinigameDialog.exec();
    std::string mini = selectMinigameDialog.getSelectedMinigame();

    if(mini.compare("Random Chance") == 0)
    {
        RandomChance mini(this);
        mini.exec();
        return mini.isWin();
    }
    else if(mini.compare("Trivia") == 0)
    {
        Trivia mini(this);
        mini.exec();
        return mini.isWin();
    }
    else if(mini.compare("Stone Paper Scissors")==0)
    {
        StonePapersScissors mini(this);
        mini.exec();
        return mini.isWin();
    }
    else if(mini.compare("Jackpot") == 0)
    {
        coinToss mini(this);
        mini.exec();
        return mini.isWin();
    }
    else if(mini.compare("Blackjack") == 0)
    {
        BlackJack mini(this);
        mini.exec();
        return mini.isWin();
    }
    else if(mini.compare("Android Quiz") == 0)
    {
        AndroidQuiz mini(this);
        mini.exec();
        return mini.isWin();
    }
    else if(mini.compare("Cricket") == 0)
    {
        bookcricket mini(this);
        mini.exec();
        return mini.isWin();
    }
    else if(mini.compare("Bomb Mine") == 0)
    {
        hammer mini(this);
        mini.exec();
        return mini.isWin();
    }
    else if(mini.compare("Luck and Skill") == 0)
    {
        LuckAndSkill mini(this);
        mini.exec();
        return mini.isWin();
    }
    else if(mini.compare("Match Pattern") == 0)
    {
        MatchPattern mini(this);
        mini.exec();
        return mini.isWin();
    }
    else if(mini.compare("Whack A Mole") == 0)
    {
        WhackMole mini(this);
        mini.exec();
        return mini.isWin();
    }


    /***** TODO *****/
    //else if
    //...
    //...

    return false;
}

void MainWindow::showWin()
{
    if(player_turn == _p1) {
        showXWin();
    }
    else {
        showOWin();
    }
}

void MainWindow::showXWin()
{
    ui->t_result->setText(QString("Player 'X' Wins!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}

void MainWindow::showOWin()
{
    ui->t_result->setText(QString("Player 'O' Wins!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}


void MainWindow::showTie()
{
    ui->t_result->setText(QString("Tie!"));
    ui->t_result->setAlignment(Qt::AlignCenter);
}


/**** PRIVATE SLOTS ****/

void MainWindow::on_b_tile_clicked()
{
    /*** handle to clicked button ***/
    Tile* button = (Tile* )sender();

    /*** is this a valid tile to click ***/
    if( !button->isEmpty())
        return;

    /*** play minigame ***/
    bool didWinMini = playMini();

    /*** Maximum number of turns possible on board ***/
    int tileSize=this->board_size*this->board_size;
    this->size++;

    /*** player won minigame ***/
    if(didWinMini) {
        button->handleClicked(player_turn);
    }
    /*** player lost minigame ***/
    else {
        togglePlayer();
        button->handleClicked(player_turn);
        togglePlayer();
    }

    /*** store tile change in backend ***/
    resultArray[button->getRow()][button->getCol()]=button->getValue();

    /*** win ***/
    if(checkWin() == 1) {
        if( !didWinMini)
            togglePlayer(); // other player won game
        showWin();
        disableTileClicks();//disable button clicks, can only click end game
        this->player_turn = _p1; // X is first at start of every game
        return;
    }
    /*** draw ***/
    else if(this->size == tileSize) {
        disableTileClicks();
        showTie();
        this->player_turn = _p1; // X is first at start of every game
        return;
    }

    button->setEnabled(false);
    togglePlayer();

    /*** AI ***/
    if(this->flagAI)
    {
        while(true)
        {
            int i=rand()%this->board_size;
            int j=rand()%this->board_size;
            if(resultArray[i][j]!='X' && resultArray[i][j]!='O')
            {
                /*** lay AI's choice ***/
                this->size++;
                tile[i][j]->setValue('O');
                tile[i][j]->setEnabled(false);
                resultArray[i][j]='O';

                /*** win ***/
                if(checkWin())
                {
                    showWin();
                    disableTileClicks(); //disable button clicks, can only click end game
                    togglePlayer(); //switch turn to human
                    return;
                }
                /*** draw ***/
                else if(this->size == tileSize)
                {
                    showTie();
                    disableTileClicks(); //disable button clicks, can only click end game
                    togglePlayer(); //switch turn to human
                    return;
                }

                togglePlayer(); //switch turn to human
                return;
            }
        }
    }
}


void MainWindow::on_b_singleplayer_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->w_play);
    this->flagAI=1;
    configureBoard();
}

void MainWindow::on_b_multiplayer_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->w_play);
    this->flagAI=0;
    configureBoard();
}

void MainWindow::on_b_main_menu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->w_main);
}

void MainWindow::on_b_end_game_clicked()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            resultArray[i][j]=' ';

    for(int i=0;i<board_size;i++)
        for(int j=0;j<board_size;j++)
            delete tile[i][j];

    ui->stackedWidget->setCurrentWidget(ui->w_main);
}


/***** BACKEND *****/

/*
 * Function Description: checkWin()
 * Checks for consecutive 'X' or 'O' (matches) in each row, column and diagonal
 *
 * Returns:
 * 1 on success
 */
int MainWindow::checkWin()
{
    int n = this->board_size;

    /*
     * Row Check:
     * Check each row for n consecutive 'X' or 'O' and
     * return 1 on success
     */

    for(int rowCount = 0; rowCount < n; rowCount++) {
        int max1 = 0, max2 = 0;

        for(int columnCount = 0; columnCount < n; columnCount++) {
            if(resultArray[rowCount][columnCount] == 'X')
                max1++;
            if(resultArray[rowCount][columnCount] == 'O')
                max2++;
        }

        if(max1 == this->board_size || max2 == this->board_size) {
            for(int i = 0; i < this->board_size; i++){
                tile[rowCount][i]->setHighlight();
            }
            return 1;
        }
    }


    /*
     * Column Check:
     * Check each column for n consecutive 'X' or 'O' and
     * return 1 on success
     */
    for(int rowCount = 0;rowCount < n;rowCount++) {
        int max3 = 0, max4 = 0;

        for(int columnCount = 0; columnCount < n; columnCount++) {
            if(resultArray[columnCount][rowCount] == 'X')
                max3++;
            if(resultArray[columnCount][rowCount] == 'O')
                max4++;
        }

        if(max3 == this->board_size || max4 == this->board_size) {
            for(int i = 0; i < this->board_size; i++) {
                tile[i][rowCount]->setHighlight();
            }

            return 1;
        }
    }


    /*
     * Diagonal check1:
     * Check the diagonal starting from leftmost top to rightmost bottom tile
     */
    int max5 = 0, max6 = 0;

    for(int rowColumnCount = 0; rowColumnCount < n; rowColumnCount++) {
        if(resultArray[rowColumnCount][rowColumnCount] == 'X')
            max5++;
        if(resultArray[rowColumnCount][rowColumnCount] == 'O')
            max6++;
    }

    if(max5 == this->board_size || max6 == this->board_size) {
        for(int i = 0; i < this->board_size; i++) {
            tile[i][i]->setHighlight();
        }

        return 1;
    }


    /* Diagonal Check 2:
     * Check the diagonal starting from rightmost top to leftmost bottom tile
     */
    int max7 = 0, max8 = 0;

    for(int rowCount = 0,columnCount = n-1; columnCount >= 0; rowCount++, columnCount--) {
        if(resultArray[columnCount][rowCount]=='X')
            max7++;
        if(resultArray[columnCount][rowCount]=='O')
            max8++;
    }

    if(max7 == this->board_size || max8 == this->board_size) {
        for(int i = 0, j = n-1; j >= 0; i++, j--) {
            tile[i][j]->setHighlight();
        }

        return 1;
    }

    return 0;
}


void MainWindow::on_b_about_clicked()
{
    AboutDialog dialog(this);
    dialog.exec();
}
