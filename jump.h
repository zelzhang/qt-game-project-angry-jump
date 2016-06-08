#ifndef JUMP_H
#define JUMPE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class JUMP
        : public QWidget
{
    Q_OBJECT
public:
    explicit JUMP(QWidget *parent = 0);
    ~JUMP();

private:
    QTimer *JUMPTimer;

protected:
    void paintEvent(QPaintEvent *);


};
#endif // JUMP_H
