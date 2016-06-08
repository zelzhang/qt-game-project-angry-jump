#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>

class OBSTACLE
        : public QWidget
{
    Q_OBJECT
public:
    explicit OBSTACLE(QWidget *parent = 0);
    ~OBSTACLE();

    int getH();
    int getW();
    int getG();
    int getP();
    void setP(int,int);
    void setW(int);

private:
    int height, width, gap, pic;
    QString Img[3];
protected:
    void paintEvent(QPaintEvent *);


};

#endif // OBSTACLE_H
