#include "obstacle.h"
OBSTACLE::OBSTACLE(QWidget *parent) : QWidget(parent)
{
    pic = 0;
    width = 100;
    height = 30;
    gap = 200;
    this->setFixedSize(width, height);

    Img[0] = ":/Image/white.png";
    Img[1] = ":/Image/gray.png";
    Img[2] = ":/Image/blue.png";
}

OBSTACLE::~OBSTACLE()
{

}
void OBSTACLE::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(Img[pic]);
    painter.drawPixmap(0,0,width, height,pix);
}

int OBSTACLE::getH()
{
    return height;
}

int OBSTACLE::getW()
{
    return width;
}

int OBSTACLE::getG()
{
    return gap;
}
int OBSTACLE::getP()
{
    return pic;
}
void OBSTACLE::setP(int num, int hard){
    qsrand(num);
    int a = qrand()%10;
    if(a == 9){
        pic =2 ;
    }
    else if(a < 2){
        if(hard == 0) pic =1 ;
        else pic = 0;
    }
    else{
        if(hard == 0) pic =0 ;
        else pic = 1;
    }
}
void OBSTACLE::setW(int num){
    width = num;
}
