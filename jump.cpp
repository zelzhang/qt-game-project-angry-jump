#include "jump.h"

JUMP::JUMP(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(188,84);
}

JUMP::~JUMP()
{

}

void JUMP::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/jump.png");
    painter.drawPixmap(0,0,188,84,pix);
}

