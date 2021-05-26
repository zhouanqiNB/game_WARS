#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include<QPixmap>


class myPushButton : public QPushButton
{
    Q_OBJECT
public:

    myPushButton(QString common,QString stop="");

    QString common,stop;

    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);

    QPixmap pix;

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
