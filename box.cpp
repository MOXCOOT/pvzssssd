#include "box.h"
#include "sun_num.h"

#include <QtWidgets>

Box::Box()
{
    cnt = 0;
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

QRectF Box::boundingRect() const
{
    return QRectF(-190,-30,250,140);
}

void Box::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->scale(.6, .58);
    painter->drawPixmap(QRect(-190,-30,250,140), QPixmap(":/image/images/Box_" + name + ".png"));
//    painter->drawPixmap(QRect(-190,-30,250,140), QPixmap(":/image/images/BBB.png"));
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(-30, 90, QString().sprintf("%3d", cost));


    QBrush brush(QColor(0, 0, 0, 150));
    painter->setBrush(brush);
    Sun_Num *tou = qgraphicsitem_cast<Sun_Num *>(scene()->items(QPointF(400, 100))[0]);
    if(tou->sun < this->cost)
    {
         painter->drawRect(QRectF(-190, -27, 250 , 150));
    }

    if (cnt < cooltime)
    {
        painter->drawRect(QRectF(-190, -27, 250 * (1 - (qreal)cnt / cooltime), 150));
//        QBrush brushright(QColor(0,0,0,100));
//        painter->setBrush(brushright);
//        painter->drawRect(QRectF(-190, -27, 250 *  (qreal)cnt / cooltime, 150));
//        painter->drawRect(QRectF(-48, -68, 98, 132 * (1 - qreal(counter) / cool[map[text]])));
    }
}

void Box::advance(int phase)
{
    if(!phase)return;
    update();
    if (cnt < cooltime)
        ++cnt;
}

void Box::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    Sun_Num *sunnum = qgraphicsitem_cast<Sun_Num *>(scene()->items(QPointF(400, 100))[0]);
    if (cnt < cooltime || cost > sunnum->sun)
    {
        event->setAccepted(false);
        return;
    }
//    setCursor(Qt::ArrowCursor);
    setCursor(Qt::ClosedHandCursor);
}

void Box::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
            < QApplication::startDragDistance())
        return;
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    QImage image(":/image/images/Plant_" + name + ".png");
    mime->setImageData(image);
    mime->setText(name);
    drag->setPixmap(QPixmap::fromImage(image).scaled(90, 80));
    drag->setHotSpot(QPoint(35, 35));
    drag->setMimeData(mime);
    drag->exec();
//    setCursor(Qt::ArrowCursor);
    setCursor(Qt::OpenHandCursor);
}



void Box::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::OpenHandCursor);
//    setCursor(Qt::ArrowCursor);
}
