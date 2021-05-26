#ifndef MYCHARACTER2_H
#define MYCHARACTER2_H

#include <QMainWindow>
#include"chooseicon2.h"
#include<QTextEdit>

class mycharacter2 : public QMainWindow
{
    Q_OBJECT
public:
    explicit mycharacter2(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

    chooseIcon2* chooseicon2=NULL;

    myPushButton* yesBtn=NULL;
    myPushButton* homeBtn=NULL;
    myPushButton* backBtn=NULL;

    QTextEdit* name=NULL;

signals:
    void myCharacter2Back();
    void myCharacter2Home();


public slots:
};

#endif // MYCHARACTER2_H
