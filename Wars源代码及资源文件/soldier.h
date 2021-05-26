#ifndef SOLDIER_H
#define SOLDIER_H

#include <QObject>


class Soldier : public QObject
{
    Q_OBJECT
public:
    explicit Soldier(QObject *parent = nullptr);

    void setSoldier(QString);

    QString name="";
    int lifeValue;
    int attackValue;
    int distance;
    QString icon;
    int character=0;

    bool haveBeenAttacked=0;

    bool pin=0;

    bool isProtected=0;

    bool readyToSkill=0;

    QString getIcon()const;
    void setIcon(QString i);

    QString getName()const;
    void setName(QString i);

    void lifeThing();













signals:
   void iconChanged(QString);
   void nameChanged(QString);
   void lifeChanged(QString);
   void attackChanged(QString);
   void distanceChanged(QString);
   void lifeZero();

public slots:
};

#endif // SOLDIER_H
