#include "sun_num.h"
#include "energy.h"
#include "QDebug"
Sun_Num::Sun_Num()
{
    sun = 100;
}

QRectF Sun_Num::boundingRect() const
{
    return QRectF(-190,-30,250,140);
}

void Sun_Num::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    painter->drawPixmap(QRect(-125,-15,176,98), QPixmap(":/image/images/BBB.png"));
    QFont font;
    font.setPointSizeF(30);
    painter->setFont(font);
    painter->drawText(-60, 50, QString().sprintf("%3d", sun));
}

void Sun_Num::advance(int phase)
{
    if(!phase)
        return;
    update();
    static int cnt =0;
    static int time = 200;
    if(cnt++>time)
    {
        cnt =0;
        scene()->addItem(new Energy);
    }
}
