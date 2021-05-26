#ifndef INTROSTORY_H
#define INTROSTORY_H

#include <QMainWindow>
#include<QLabel>
#include"mypushbutton.h"

class introStory : public QMainWindow
{
    Q_OBJECT
public:
    explicit introStory(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

    myPushButton* homeBtn=NULL;
    myPushButton* backBtn=NULL;




signals:

    void introBack();
    void introHome();

public slots:
};

#endif // INTROSTORY_H
