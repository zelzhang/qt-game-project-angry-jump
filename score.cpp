#include "score.h"

void SCORE::change_type(char type){
    this->setFixedSize(600,600);
    wid = 100;
    hei = 30;
    error = 5;
    switch(type){
    case 's':
        score = 1;
        break;
    case 'h':
        score = 0;
        break;
    default:
        break;
    }

}
SCORE::SCORE(QWidget *parent) : QWidget(parent)
{
    score = 0;

}

SCORE::~SCORE()
{

}

void SCORE::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    if(score == 1){
        pix.load(":/Image/score.png");

    }else{
        pix.load(":/Image/highscore.png");

    }
    painter.drawPixmap(0,0,wid,hei,pix);
}

