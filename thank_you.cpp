#include "thank_you.h"

THANK_YOU::THANK_YOU(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(232,157);
}

THANK_YOU::~THANK_YOU()
{

}

void THANK_YOU::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/thank_you.png");
    painter.drawPixmap(0,0,232,157,pix);
}

