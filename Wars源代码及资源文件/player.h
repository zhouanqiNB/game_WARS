#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include"soldier.h"

class player : public QObject
{
    Q_OBJECT
public:
    explicit player(QObject *parent = nullptr);
    QString name;
    Soldier s[3];

    QString getIcon()const;
    void setIcon(QString i);

    QString getName()const;
    void setName(QString i);
signals:
    void iconChanged(QString);

    void nameChanged(QString);
public slots:

private:
    QString headIcon;
};

#endif // PLAYER_H
