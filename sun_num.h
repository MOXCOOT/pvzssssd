#ifndef SUN_NUM_H
#define SUN_NUM_H

#include "box.h"

#include <QGraphicsItem>
class Sun_Num : public QGraphicsItem
{
public:
    int sun;
    Sun_Num();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
};

#endif // SUN_NUM_H
