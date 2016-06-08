#ifndef FLOOR_H
#define FLOORE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class FLOOR
        : public QWidget
{
    Q_OBJECT
public:
    int status;
    int size;
    explicit FLOOR(QWidget *parent = 0);
    ~FLOOR();

private:
    int floor_width;
    int floor_height;
    QTimer *floorTimer;
    QString floorImg[10];

protected:
    void paintEvent(QPaintEvent *);


};
#endif // FLOOR_H
