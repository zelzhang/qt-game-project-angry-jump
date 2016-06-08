#include "number.h"

NUMBER::NUMBER(QWidget *parent) : QWidget(parent)
{
    wid = 10;
    hei = 30;
    this->setFixedSize(600,600);
    data = 0;
    numImg[0] = ":/Image/0.png";
    numImg[1] = ":/Image/1.png";
    numImg[2] = ":/Image/2.png";
    numImg[3] = ":/Image/3.png";
    numImg[4] = ":/Image/4.png";
    numImg[5] = ":/Image/5.png";
    numImg[6] = ":/Image/6.png";
    numImg[7] = ":/Image/7.png";
    numImg[8] = ":/Image/8.png";
    numImg[9] = ":/Image/9.png";
}

NUMBER::~NUMBER()
{

}

void NUMBER::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    int n1 = data/100;
    int n2 = (data/10)%10;
    int n3 = (data%100)%10;
    pix.load(numImg[n1]);
    painter.drawPixmap(0,0,wid,hei,pix);
    pix.load(numImg[n2]);
    painter.drawPixmap(wid,0,wid,hei,pix);
    pix.load(numImg[n3]);
    painter.drawPixmap(wid*2,0,wid,hei,pix);
}

