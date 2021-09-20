#include "zombie_rugby.h"

Zombie_Rugby::Zombie_Rugby()
{
    condition = 1;
    bv = 100;
    ht = 50;
    speed  = 3;
    setMovie(":/image/images/FootballZombieWalk.gif");
    sound = new QSound(":/image/sound/zombie——eat.wav");
    sound->setLoops(1);
}

void Zombie_Rugby::advance(int phase)
{
    if(!phase)return;
    update();
    if(bv<=0){
        if(condition)
        {
            condition = 0;
            setMovie(":/image/images/FootballZombieDie.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }
    else{
        QList<QGraphicsItem *> items = collidingItems();
        if(!items.isEmpty())
        {
            if(condition == 1 )
            {
                setMovie(":/image/images/FootballZombieAttack.gif");
                condition = 2;
            }
            Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
            plant->bv -= ht;
            if(sound->isFinished())
            {
                sound->play();
            }
            return;
        }
        else {
            if(condition == 2){
                condition = 1;
                setMovie(":/image/images/FootballZombieWalk.gif");
            }
        }
    }
    setX(x()-speed);
}
