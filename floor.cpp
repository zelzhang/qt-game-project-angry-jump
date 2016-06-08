#include "floor.h"

FLOOR::FLOOR(QWidget *parent) : QWidget(parent)
{
    floor_width = 380;
    floor_height = 500;
    this->setFixedSize(380,500);
    status = 0;
    floorImg[0] = ":/Image/help_content.png";
    floorImg[1] = ":/Image/angry.png";
    floorImg[2] = ":/Image/jump.png";
    floorImg[3] = ":/Image/thank_you.png";
    floorImg[4] = ":/Image/angry_start.png";
}

FLOOR::~FLOOR()
{

}

void FLOOR::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(floorImg[status]);
    if(status == 0) painter.drawPixmap(0,0,floor_width,floor_height,pix);
    else if(status == 1) painter.drawPixmap(0,0,188,84,pix);
    else if(status == 2) painter.drawPixmap(0,0,188,84,pix);
    else if(status == 3) painter.drawPixmap(0,0,232,157,pix);
    else if(status == 4) painter.drawPixmap(0,0,size,size,pix);
}

