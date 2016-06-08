#include "start.h"

START::START(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(600,600);
    wid = 150;
    hei = 75;
    red = 0;
    type = 0;
}

START::~START()
{

}

void START::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    if(type == 0){
        if(red == 1)pix.load(":/Image/play.png");
        else pix.load(":/Image/play0.png");
    }
    else if(type == 1){
        if(red == 1)pix.load(":/Image/help.png");
        else pix.load(":/Image/help0.png");
    }
    else if(type == 2){
        if(red == 1)pix.load(":/Image/quit.png");
        else pix.load(":/Image/quit0.png");
    }else{
        pix.load(":/Image/thank_you.png");
    }
    painter.drawPixmap(0,0,wid,hei,pix);
}

void START::change_type(int type_num){
    type = type_num;

}
void START::activate(){
    red = 1;
}
void START::disable(){
    red = 0;
}
void START::change_WH(int wei ,int hein){
    wid = wei;
    hei = hein;
}
