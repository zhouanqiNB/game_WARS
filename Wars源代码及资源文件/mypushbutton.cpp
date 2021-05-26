#include "mypushbutton.h"
#include<QString>
#include<QPushButton>

myPushButton::myPushButton(QString common,QString stop)
{
    this->common=common;
    this->stop=stop;

    pix.load(common);

    this->resize(pix.width()*0.65,pix.height()*0.65);
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width()*0.65,pix.height()*0.65));

}

void myPushButton::enterEvent(QEvent *)
{
    QPixmap pix1;
    pix1.load(stop);
    this->setIcon(pix1);
}
void myPushButton::leaveEvent(QEvent *)
{
    QPixmap pix1;
    pix1.load(common);
    this->setIcon(pix1);
}

