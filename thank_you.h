#ifndef THANK_YOU_H
#define THANK_YOUE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class THANK_YOU
        : public QWidget
{
    Q_OBJECT
public:
    int size;
    explicit THANK_YOU(QWidget *parent = 0);
    ~THANK_YOU();

private:
    QTimer *THANK_YOUTimer;

protected:
    void paintEvent(QPaintEvent *);


};
#endif // THANK_YOU_H
