#ifndef CHOOSEICON2_H
#define CHOOSEICON2_H

#include <QMainWindow>
#include"mypushbutton2.h"
#include"choosesoldierA.h"

class chooseIcon2 : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooseIcon2(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);

    int which=20;

    myPushButton2* icon[16];


signals:
    void chooseIconBack();
    void chooseIconHome();

public slots:
};

#endif // CHOOSEICON2_H
