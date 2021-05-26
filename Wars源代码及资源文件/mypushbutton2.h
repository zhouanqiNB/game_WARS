#ifndef MYPUSHBUTTON2_H
#define MYPUSHBUTTON2_H

#include <QWidget>
#include<QPushButton>
#include"soldier.h"
class myPushButton2 : public QPushButton
{
    Q_OBJECT
public:

    myPushButton2();
    myPushButton2(QString common,QString click="");

    void beClicked();
    void notClicked();
    void loadIcon(const QString &icon);

    bool isClicked=false;

    QString common,click;

    QString name;//用在characa里面的

    QPixmap pix;

    //棋盘算法中需要的bool
    bool blank=1;
    bool onIsA=1;

    bool isProtected=0;



signals:

public slots:
};

#endif // MYPUSHBUTTON2_H
