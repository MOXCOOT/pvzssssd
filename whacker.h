#ifndef WHACKER_H
#define WHACKER_H
#include "messy.h"
#include "zombie.h"
#include <QSound>

class Whacker : public Messy
{
public:
    Whacker();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
private:
    bool judge;
    qreal speed;
    QSound *sound3;
};

#endif // WHACKER_H
