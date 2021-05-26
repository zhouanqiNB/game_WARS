#ifndef MYCHARACTER_H
#define MYCHARACTER_H

#include"player.h"
#include"chooseicon.h"
#include <QMainWindow>
#include<QTextEdit>

extern player A;
extern player B;
class myCharacter : public QMainWindow
{
    Q_OBJECT
public:
    explicit myCharacter(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);


    myPushButton* yesBtn=NULL;
    myPushButton* homeBtn=NULL;
    myPushButton* backBtn=NULL;



    QTextEdit* name=NULL;


signals:
    void myCharacterBack();
    void myCharacterHome();

public slots:
};

#endif // MYCHARACTER_H
