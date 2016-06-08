#ifndef NUMBER_H
#define NUMBER_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>

class NUMBER
        : public QWidget
{
    Q_OBJECT
public:
    explicit NUMBER(QWidget *parent = 0);
    ~NUMBER();
    int data;
    int wid;
    int hei;
private:
    QString numImg[10];

protected:
    void paintEvent(QPaintEvent *);


};

#endif // NUMBER_H
