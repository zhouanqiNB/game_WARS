#ifndef CHOOSEICON_H
#define CHOOSEICON_H

#include <QMainWindow>
#include"mypushbutton2.h"
#include"mycharacter2.h"

class chooseIcon : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooseIcon(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);

    int which=20;

    myPushButton2* icon[16];



signals:
    void chooseIconBack();
    void chooseIconHome();

public slots:
};

#endif // CHOOSEICON_H
