#ifndef WEAPON_H
#define WEAPON_H
#include<QGraphicsItem>
#include<QMovie>
#include<QPainter>
#include <QSound>

class Weapon : public QGraphicsItem
{
public:
    Weapon();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *weapon, Qt::ItemSelectionMode mode) const override;
    void advance(int phase)override;
    bool frozen;
    qreal speed;
    int ht;
    QSound *sound2;
};

#endif // WEAPON_H
