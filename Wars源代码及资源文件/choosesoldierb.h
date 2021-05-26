#ifndef CHOOSESOLDIERB_H
#define CHOOSESOLDIERB_H

#include <QMainWindow>
#include"mypushbutton2.h"
#include"player.h"
#include"introsoldier.h"
#include"playtable.h"
#include"transparentbutton.h"

class chooseSoldierb : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooseSoldierb(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

    myPushButton2* icon[10];

    int whichIsClicked=0;//用来表示哪个t被clicked了
    introSoldier* in=NULL;
    transparentButton*t[3];



signals:

    void Home();
    void Back();


public slots:
};

#endif // CHOOSESOLDIERB_H
