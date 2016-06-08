#include "role.h"

ROLE::ROLE(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(35,35);
    i=0;
    size = 35;
    falling = 0;
    crashing = 0;
    roleImg[0] = ":/Image/bird2.png";
    roleImg[1] = ":/Image/bird1.png";
    roleTimer = new QTimer(this);
    connect(roleTimer, SIGNAL(timeout()), this, SLOT(update()));
    roleTimer->start(10000);
}

ROLE::~ROLE()
{

}

void ROLE::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    if(falling == 0){
        pix.load(roleImg[1]);
    }else
        pix.load(roleImg[0]);
    painter.drawPixmap(0,0,size,size,pix);
}

