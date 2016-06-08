#ifndef ANGRY_H
#define ANGRYE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class ANGRY
        : public QWidget
{
    Q_OBJECT
public:
    explicit ANGRY(QWidget *parent = 0);
    ~ANGRY();

private:
    QTimer *ANGRYTimer;

protected:
    void paintEvent(QPaintEvent *);


};
#endif // ANGRY_H
