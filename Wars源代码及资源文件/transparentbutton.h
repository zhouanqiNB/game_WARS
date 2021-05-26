#ifndef TRANSPARENTBUTTON_H
#define TRANSPARENTBUTTON_H

#include <QMainWindow>
#include"mypushbutton2.h"

class transparentButton : public myPushButton2
{
    Q_OBJECT
public:
    explicit transparentButton(QString common,QString click);

    QString common,click;

signals:

public slots:
};

#endif // TRANSPARENTBUTTON_H
