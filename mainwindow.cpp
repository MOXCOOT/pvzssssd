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
#include "plant_cherrybomb.h"
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
#include "sunner.h"
#include "energy.h"
#include "zombie_block.h"
#include "plant_peasnow.h"
#include <qgraphicsitem.h>
#include <QSound>
#include "zombie_bucket.h"
#include "box.h"
#include "zombie_jump.h"
#include "zombie_rugby.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));
    sound = new QSound(":/image/sound/egypt.wav",this);
    sound->play();
    sound->setLoops(QSound::Infinite);

//    Dave = new QMovie(":/image/images/Dave.gif");

    sound2 = new QSound(":/image/sound/lose.wav",this);
    sound2->setLoops(1);
    ui->setupUi(this);
    timer= new QTimer;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(360, 120, 900, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);


    //
    Sun_Num *po = new Sun_Num;
    po->setPos(400,100);
    scene->addItem(po);


    //

    Lawn *LL = new Lawn;
    LL->setPos(517,180);
    scene->addItem(LL);

//添加僵尸
//    Zombie *b =new Zombie_Jump;
//    b->setPos(1220, 215);
//    Zombie *a =new Zombie_Basic;
//    a->setPos(1220,315);
//    Zombie *c = new Zombie_Jump;
//    c->setPos(1220,415);
//    scene->addItem(b);
//    scene->addItem(a);
//    scene->addItem(c);

//添加卡片
    Box *x = new Box_Chomper;
    x->setPos(400,200);
    scene->addItem(x);

    Box *y = new Box_Peashooter;
    y->setPos(400,280);
    scene->addItem(y);

    Box *al = new Box_GrounAttack;
    al->setPos(400,360);
    scene->addItem(al);

    Box *ll = new Box_SunFlower;
    ll->setPos(400,440);
    scene->addItem(ll);

    Box *l2 = new Box_Shield;
    l2->setPos(400,520);
    scene->addItem(l2);


    Box *l3 = new Box_CherryBomb;
    l3->setPos(400,600);
    scene->addItem(l3);

    Box *l4 = new Box_SnowPea;
    l4->setPos(400,680);
    scene->addItem(l4);

//添加除草机

    view = new QGraphicsView(scene, this);    for(int i=0;i<5;i++)
    {
        Whacker *wha = new Whacker;
        wha->setPos(500,235+i*100);
        scene->addItem(wha);
    }
    view->resize(1052, 651);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap(":/image/images/Background0.jpg"));
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &MainWindow::AddZombie);
    connect(timer, &QTimer::timeout, this, &MainWindow::isfail);
    timer->start(33);
    view->show();
//    timer->stop();
//    sound->stop();
//    Dave->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddZombie(){
    static int cnt = 0;
    static int time = 300;
    static double difficult = 1;  //难度系数
    static int num = 0;
    if(cnt++>time)
    {
        num++;
        if(num >= difficult * 2)
        {
            num=0;
            difficult*=2;
            time-=difficult*10;
        }
        cnt=0;
        int tp = qrand()%6;
        int road = qrand()%5;
        Zombie *b;
        if(tp==0)
        {
            b =new Zombie_Basic;
            b->setPos(1230, 215+100*road);
        }
        else if(tp==1)
        {
            Zombie *bc =new Zombie_Jump;
            bc->setPos(1230, 215+100*road);
            scene->addItem(bc);
        }
        else if(tp==2)
        {
            b =new Zombie_Bucket;
            b->setPos(1230, 215+100*road);
            scene->addItem(b);
        }
        else if(tp==3)
        {
            b =new Zombie_Jump;
            b->setPos(1230, 215+100*road);
            scene->addItem(b);
        }
        else if(tp==5)
        {
            b =new Zombie_Rugby;
            b->setPos(1230, 215+100*road);
            scene->addItem(b);
        }
        return;

    }
}

void MainWindow::isfail()
{
    const QList<QGraphicsItem *> items = scene->items();
    foreach (QGraphicsItem *item, items)
        if (item->type() == Zombie::Type && item->x() < 480)
        {
            sound->stop();
            sound2->play();
            scene->addPixmap(QPixmap(":/image/images/YouLose.png"))->setPos(500, 150);
            scene->advance();
            timer->stop();
            return;
        }
}














