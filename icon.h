#ifndef ICON_H
#define ICONE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class ICON
        : public QWidget
{
    Q_OBJECT
public:
    int size;
    explicit ICON(QWidget *parent = 0);
    ~ICON();

private:
    QTimer *ICONTimer;

protected:
    void paintEvent(QPaintEvent *);


};
#endif // ICON_H
