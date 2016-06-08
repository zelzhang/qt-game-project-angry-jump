#ifndef SCORE_H
#define SCORE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>

class SCORE
        : public QWidget
{
    Q_OBJECT
public:
    explicit SCORE(QWidget *parent = 0);
    ~SCORE();
    void change_type(char type);
    int wid;
    int hei;
    int error;
private:
    int score; // 1->score, 0->highscore

protected:
    void paintEvent(QPaintEvent *);


};

#endif // SCORE_H
