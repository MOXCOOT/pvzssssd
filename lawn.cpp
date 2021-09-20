#include "lawn.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zombie_basic.h"
#include "zombie.h"
#include "plant.h"
#include "plant_pea.h"
#include "weapon.h"
#include "weapon_pea.h"
#include "messy.h"
#include "whacker.h"
#include "sun_num.h"
#include "plant_chomper.h"
#include "plant_shield.h"
#include "box_chomper.h"
#include "box_peashooter.h"
#include "plant_groundattack.h"
#include "box_grounattack.h"
#include "box_sunflower.h"
#include "box_snowpea.h"
#include "lawn.h"
#include "box_shield.h"
#include "box_cherrybomb.h"
#include "plant_cherrybomb.h"
#include "plant_peasnow.h"
#include<qgraphicsitem.h>
#include <QSound>
#include "sunner.h"
#include "box.h"
#include "box.h"

Lawn::Lawn()
{
    dragOver = false;
    setAcceptDrops(true);
    sound = new QSound(":/image/sound/plant——sound.wav");
    sound->setLoops(1);
}

QRectF Lawn::boundingRect() const
{
    return QRectF(0, 0, 750, 500);
}

void Lawn::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Lawn::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasText()) {
        event->setAccepted(true);
        dragOver = true;
        update();
    } else {
        event->setAccepted(false);
    }
}

void Lawn::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    dragOver = false;
    update();

}

void Lawn::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    if (event->mimeData()->hasText())
    {
        QString name =event->mimeData()->text();
        QPointF pos = mapToScene(event->pos());
        int ax = int(pos.x() - 545) / 82 * 82 + 570;
        int by = int(pos.y() - 190) / 100 * 100 + 215;
        qDebug()<<ax<<' '<<by;
//        ->childitems(QPointF(a, b))[0]
//        Plant *ppp = qgraphicsitem_cast<Plant *>(scene()->c);
//        if(ppp==nullptr)
//        {
//            map[a][b]=0;
//        }
        if(map[ax][by])
            goto stop;
        Sun_Num *tou = qgraphicsitem_cast<Sun_Num *>(scene()->items(QPointF(400, 100))[0]);
        if(name == "Peashooter" && tou->sun >= 125){
            Plant *p = new Plant_Pea;
            p->setPos(ax,by);
            scene()->addItem(p);
            Sun_Num *tou = qgraphicsitem_cast<Sun_Num *>(scene()->items(QPointF(400, 100))[0]);
            tou->sun -= 125;
            Box *b =  qgraphicsitem_cast<Box_Peashooter *> (scene()->items(QPointF(400, 280))[0]);
            b->cnt = 0;
            p->x0=ax;
            p->y0=by;
            sound->play();

        }
        if(name == "Chomper" && tou->sun >= 100){
            Plant *p =new Plant_Chomper;
            p->setPos(ax,by);
            scene()->addItem(p);
            Sun_Num *tou = qgraphicsitem_cast<Sun_Num *>(scene()->items(QPointF(400, 100))[0]);
            tou->sun -= 100;
            Box *b =  qgraphicsitem_cast<Box_Chomper *> (scene()->items(QPointF(400, 600))[0]);
            b->cnt = 0;
            p->x0=ax;
            p->y0=by;
            sound->play();
        }
        if(name == "Shield" && tou->sun >= 50){
            Plant *p = new Plant_shield;
            p->setPos(ax,by);
            scene()->addItem(p);
            Sun_Num *tou = qgraphicsitem_cast<Sun_Num *>(scene()->items(QPointF(400, 100))[0]);
            tou->sun -= 50;
            Box *b =  qgraphicsitem_cast<Box_Shield *> (scene()->items(QPointF(400, 520))[0]);
            b->cnt = 0;
            p->x0=ax;
            p->y0=by;
            sound->play();
        }
        if(name == "SunFlower" && tou->sun >= 50)
        {
            Plant *p = new Sunner;
            p->setPos(ax,by);
            scene()->addItem(p);
            Sun_Num *tou = qgraphicsitem_cast<Sun_Num *>(scene()->items(QPointF(400, 100))[0]);
            tou->sun -= 50;
            Box *b =  qgraphicsitem_cast<Box_SunFlower *> (scene()->items(QPointF(400, 440))[0]);
            b->cnt = 0;
            p->x0=ax;
            p->y0=by;
            sound->play();
        }
        if(name == "SnowPea" && tou->sun >= 175)  {
            Plant *p = new Plant_PeaSnow;
            p->setPos(ax,by);
            scene()->addItem(p);
            Sun_Num *tou = qgraphicsitem_cast<Sun_Num *>(scene()->items(QPointF(400, 100))[0]);
            tou->sun -= 175;
            Box *b =  qgraphicsitem_cast<Box_SnowPea *> (scene()->items(QPointF(400, 680))[0]);
            b->cnt = 0;
            p->x0=ax;
            p->y0=by;
            sound->play();
        }
        if(name == "GroundAttack" && tou->sun >= 200){
            Plant *p = new Plant_GroundAttack;
            p->setPos(ax,by);
            scene()->addItem(p);
            Sun_Num *tou = qgraphicsitem_cast<Sun_Num *>(scene()->items(QPointF(400, 100))[0]);
            tou->sun -= 200;
            Box *b =  qgraphicsitem_cast<Box_GrounAttack *> (scene()->items(QPointF(400, 360))[0]);
            b->cnt = 0;
            p->x0=ax;
            p->y0=by;
            sound->play();
        }
        if(name == "CherryBomb" && tou->sun >= 200){
            Plant *p = new Plant_CherryBomb;
            p->setPos(ax,by);
            scene()->addItem(p);
            Sun_Num *tou = qgraphicsitem_cast<Sun_Num *>(scene()->items(QPointF(400, 100))[0]);
            tou->sun -= 200;
            Box *b =  qgraphicsitem_cast<Box_CherryBomb *> (scene()->items(QPointF(400, 600))[0]);
            b->cnt = 0;
            p->x0=ax;
            p->y0=by;
            sound->play();

        }
        map[ax][by] = 1;

    }

    stop:;
    update();
}
