#ifndef MYSQUARE_H
#define MYSQUARE_H

#include <QObject>
#include"mypushbutton2.h"
#include"soldier.h"
class mySquare : public QObject
{
    Q_OBJECT
public:
    explicit mySquare(QObject *parent = nullptr);

    myPushButton2 *square;
    Soldier *soldi=NULL;
    bool isEmpty=1;
    bool ownerIsA=1;



signals:

public slots:
};

#endif // MYSQUARE_H
