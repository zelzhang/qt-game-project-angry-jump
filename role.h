#ifndef ROLE_H
#define ROLE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>

class ROLE : public QWidget
{
    Q_OBJECT
public:
    explicit ROLE(QWidget *parent = 0);
    ~ROLE();
public:
    void paintEvent(QPaintEvent *);
    int falling;
    int crashing;
private:
    QString roleImg[2];
    QTimer *roleTimer;
    int size;
    unsigned int i;

};

#endif // ROLE_H
