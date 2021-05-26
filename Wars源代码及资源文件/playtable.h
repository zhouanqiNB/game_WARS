#ifndef PLAYTABLE_H
#define PLAYTABLE_H

#include <QMainWindow>
#include"mypushbutton2.h"
#include"soldier.h"
#include"mysquare.h"
#include<QLabel>
class playTable : public QMainWindow
{
    Q_OBJECT
public:
    explicit playTable(QWidget *parent);

    void paintEvent(QPaintEvent*);
    myPushButton2* attack=NULL;
    myPushButton2* skill=NULL;
    myPushButton2* again=NULL;
    myPushButton2* end=NULL;
    myPushButton2* attack1=NULL;
    myPushButton2* skill1=NULL;
    myPushButton2* again1=NULL;
    myPushButton2* end1=NULL;

    QLabel* aslife[3];
    QLabel* bslife[3];
    QLabel* asattack[3];
    QLabel* bsattack[3];
    QLabel* asdistance[3];
    QLabel* bsdistance[3];

    QLabel* text1=NULL;
    QLabel* text2=NULL;
    QLabel* APoint=NULL;
    QLabel* BPoint=NULL;


    int formerx,formery;
    int laterx,latery;

    int action;

    int which_x=5,which_y=5;

    int round=1;//回合数

    int point=0;

    QString formerpic;

    Soldier currentSoldier;

    //计算中需要的bool们
    bool AreadyToAttack=0;
    bool BreadyToAttack=0;
    bool pointMinus=0;
    bool isARound=1;
    bool isBRound=0;
    bool characHaveChosen=0;
    bool canAgain=0;

    mySquare Square[5][5];




signals:
    void roundChanged(int);
    void pointChanged(int);


public slots:
};

#endif // PLAYTABLE_H
