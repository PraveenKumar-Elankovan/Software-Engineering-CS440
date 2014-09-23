#include "mini/AndroidQuiz/androidquiz.h"
#include "ui_androidquiz.h"
#include <stdlib.h>
int questionNo=0;
const char* question[]={"The Gear 2 and the gear2 Neo are smartwatches run on which OS ?",
                  "Which open source Android-based OS is inspired from the movie \'Blade Runner\' ?",
                  "Yota is a smartphone manufacturer from which country ?",
                 "Who was the co-founder of Android who once was the VP at T-Mobile ?",
                 "The Ascend is an android phone produced by which company ?",
                 "Which phone won the GSMA top smartphone at the Mobile world congress in 2014 ?",
                 "Sundar Pichai, who oversees android, Chrome and app at Google, was born in which country ?",
                 "Which of this is an android app that allows you to share info between your android device and chrome browser ?",
                 "In relation to android, what is \'Prey\' ?",
                 "What was the first game to be developed on the android platform ?",
                 "ViewSonic is headquartered in which Californian City ?",
                 "What is the name of the town where Android was founded ?",
                 "In relation to Android what does the term \'Form Factor\' mean ?",
                 "Concerning the SDK for Android 2.2, what is Froyo short for ?",
                 "Which was the first handset with the snapdragon 800 SOC ?",
                 "The flyer and Jetstream are tablets from which company using android ?",
                 "Which of these \'endless running games\' is developed by Kiloo Games ?",
                 "By what name is the Android 3.0 SDK better known as ?",
                 "Android C2DM is better known as _________",
                 "What does GCM stand for ?",
                 "In what year was Google founded ?"};
const char* a0[]={"Sailfish OS","Tizen","Symbian","Firefox OS"};
const char* a1[]={"Chew","Holden","Deckard","Replicant"};
const char* a2[]={"Israel","South Korea","Spain","Russia"};
const char* a3[]={"Ann Mather","Rich Miner","ChrisWhite","Nick Sears"};
const char* a4[]={"Lenova","Archos","LG","Huawei"};
const char* a5[]={"Samsung Galaxy S5","Sony Xperia","Motorola Moto","HTC One"};
const char* a6[]={"India","England","SriLanka","Canada"};
const char* a7[]={"DropBox","Prizmo","Msecure","Pushbullet"};
const char* a8[]={"A Game","Development Kit","Anti-theft SW","A Web browser"};
const char* a9[]={"Sonic Dash","Tetris","Flappy Bird","Snake"};
const char* a10[]={"Palo Alto","San Diego","Walnut","Bakersfield"};
const char* a11[]={"Palo Alto","San Diego","Walnut","Bakersfield"};
const char* a12[]={"Phone's weight","Phone's shape","Phone's data","Phone's reliability"};
const char* a13[]={"Frozen Yams","Free Yogurt","Frozen Yogurt","Free Years"};
const char* a14[]={"LG G2","Samsung Galaxy S4","Samsung Galaxy Note 3","Sony Xperia Z ultra"};
const char* a15[]={"Sony","HTC","Samsung","Motorola"};
const char* a16[]={"Pepsiman","Sonic Dash","Temple Run","Subway Surfers"};
const char* a17[]={"GingerBread","Froya","Eclair","Honeycomb"};
const char* a18[]={"Google Cloud Messaging","Google Play","Google maps","Google travel"};
const char* a19[]={"Google Ctrl Messaging","Google Cloud Monitor","General Ctrl Messaging","Google Cloud Messaging"};
const char* a20[]={"2000","2003","1998","1995"};

const int answers[]={1,3,3,3,3,3,0,3,2,3,2,0,1,2,3,1,3,3,0,3,2};
/****************
 * Do not modify
 ****************/
AndroidQuiz::AndroidQuiz(QWidget *parent) :
    QDialog(parent, Qt::CustomizeWindowHint  | Qt::WindowTitleHint ),
    Minigame(),
    ui(new Ui::AndroidQuiz)
{

    ui->setupUi(this);
    ui->b_ok->setEnabled(false);
    srand(time(0));
    questionNo=rand() % 21;
    ui->question->setText(question[questionNo]);
    if(questionNo==0)    configureGame(a0);
    if(questionNo==1)    configureGame(a1);
    if(questionNo==2)    configureGame(a2);
    if(questionNo==3)    configureGame(a3);
    if(questionNo==4)    configureGame(a4);
    if(questionNo==5)    configureGame(a5);
    if(questionNo==6)    configureGame(a6);
    if(questionNo==7)    configureGame(a7);
    if(questionNo==8)    configureGame(a8);
    if(questionNo==9)    configureGame(a9);
    if(questionNo==10)    configureGame(a10);
    if(questionNo==11)    configureGame(a11);
    if(questionNo==12)    configureGame(a12);
    if(questionNo==13)    configureGame(a13);
    if(questionNo==14)    configureGame(a14);
    if(questionNo==15)    configureGame(a15);
    if(questionNo==16)    configureGame(a16);
    if(questionNo==17)    configureGame(a17);
    if(questionNo==18)    configureGame(a18);
    if(questionNo==19)    configureGame(a19);
    if(questionNo==20)    configureGame(a20);
}

/****************
 * Clean all minigame code
 ****************/
AndroidQuiz::~AndroidQuiz()
{
    for(int i = 0; i < num3; i++)
        delete this->tile[i];
    delete ui;
}

/******** PRIVATE **********/

/****************
 * Configure minigame
 ****************/
void AndroidQuiz::configureGame(const char* a[])
{

    srand(time(0));
    for(int index = 0; index < num3; index++)
    {
        tile[index] = new AndroidQuizTile(index, a[index], this);
        tile[index]->setText(QString(a[index]));
        tile[index]->setFixedSize(150, 150);
        connect(tile[index], SIGNAL(clicked()), this, SLOT(on_b_tile_clicked()));
        ui->answerGrid->addWidget(tile[index], 0, index);

    }
}

void AndroidQuiz::disableGame()
{
    for(int i = 0; i < num3; i++)
        this->tile[i]->setEnabled(false);
}

/****************
 * Do not modify
 ****************/
void AndroidQuiz::setWin()
{
    Minigame::setWin();

}

/****************
 * Do not modify
 ****************/
void AndroidQuiz::setLose()
{
    Minigame::setLose();
    }

/****************
 * Do not modify
 ****************/
void AndroidQuiz::quit()
{
    Minigame::quit();
    disableGame();
    ui->b_ok->setEnabled(true);
}

/******** PRIVATE SLOTS **********/


/****************
 * Set win or lose
 ****************/
void AndroidQuiz::on_b_tile_clicked()
{

    AndroidQuizTile* tile = (AndroidQuizTile*)sender();
    int index;
    index=tile->getIndex();
    if(index==answers[questionNo])
    {
        setWin();
        tile->setStyleSheet("background-color:Green;");
    }
    else
    {
        setLose();
        tile->setStyleSheet("background-color:Red;");
        int a=answers[questionNo];
        AndroidQuiz::tile[a]->setStyleSheet("background-color:Green;");
 }
    quit();


}




/****************
 * Do not modify
 ****************/
void AndroidQuiz::on_b_ok_clicked()
{
    this->done(QDialog::Accepted);
}
