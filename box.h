#ifndef BOX_H
#define BOX_H
#include "messy.h"
#include <QPainter>
#include <QDrag>

class Box : public Messy
{
public:
    Box();
    QString name;
    int cnt;
    int cost;
    int cooltime;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // BOX_H
