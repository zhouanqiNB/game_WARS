#ifndef INTRORULE_H
#define INTRORULE_H

#include <QMainWindow>
#include<QString>
#include"mypushbutton.h"
#include"mypushbutton2.h"

class introRule : public QMainWindow
{
    Q_OBJECT
public:
    explicit introRule(QWidget *parent = nullptr);

    QString bg[6];
    QString p[6];

    int page=0;

    void paintEvent(QPaintEvent*);


signals:
    void Home();
    void Back();

public slots:
};

#endif // INTRORULE_H
