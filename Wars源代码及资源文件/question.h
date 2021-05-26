#ifndef QUESTION_H
#define QUESTION_H

#include <QMainWindow>
#include<QDialog>
#include"mypushbutton.h"
#include<QLabel>

class Question : public QDialog
{
    Q_OBJECT
public:
    Question();
    void paintEvent(QPaintEvent *);

    myPushButton* yesBtn=NULL;
    QLabel* word=NULL;

    void setQues(int);


signals:
    void quesClose();


public slots:
};

#endif // QUESTION_H
