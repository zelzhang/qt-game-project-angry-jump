#ifndef START_H
#define START_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>

class START
        : public QWidget
{
    Q_OBJECT
public:
    explicit START(QWidget *parent = 0);
    ~START();
    void change_type(int);
    void activate();
    void disable();
    void change_WH(int ,int);
private:
    int i;
    int red;
    int wid;
    int hei;
    int type; //0:play; 1:help 2:quit
protected:
    void paintEvent(QPaintEvent *);


};

#endif // START_H
