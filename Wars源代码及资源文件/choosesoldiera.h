#ifndef CHOOSESOLDIERA_H
#define CHOOSESOLDIERA_H

#include <QMainWindow>
#include"mypushbutton2.h"
#include"player.h"
#include"choosesoldierb.h"
#include"introsoldier.h"
#include"transparentbutton.h"

class chooseSoldierA : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooseSoldierA(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    myPushButton2* icon[10];

    int whichIsClicked=0;//用来表示哪个t被clicked了
    transparentButton*t[3];

    introSoldier* in=NULL;





signals:

    void Home();
    void Back();



public slots:

};

#endif // CHOOSESOLDIERA_H
