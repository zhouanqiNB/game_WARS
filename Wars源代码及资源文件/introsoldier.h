#ifndef INTROSOLDIER_H
#define INTROSOLDIER_H

#include <QMainWindow>
#include<QString>
#include"mypushbutton.h"
#include"mypushbutton2.h"

class introSoldier : public QMainWindow
{
    Q_OBJECT
public:
    explicit introSoldier(QWidget *parent = nullptr);


    myPushButton2* picture=NULL;
    myPushButton2* words=NULL;

    myPushButton2* smallPic[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

    int page=0;

    QString word[10];
    QString pic[10];

    void update();

    void paintEvent(QPaintEvent *);

signals:

    void Home();
    void Back();

public slots:
};

#endif // INTROSOLDIER_H
