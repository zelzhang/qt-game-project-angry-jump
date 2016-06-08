#include "angry.h"

ANGRY::ANGRY(QWidget *parent) : QWidget(parent)
{

    this->setFixedSize(188,84);
}

ANGRY::~ANGRY()
{

}

void ANGRY::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/angry.png");
    painter.drawPixmap(0,0,188,84,pix);
}

