#include "icon.h"

ICON::ICON(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(380,500);
    size = 30;
}

ICON::~ICON()
{

}

void ICON::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/angry_start.png");
    painter.drawPixmap(0,0,size,size,pix);
}

