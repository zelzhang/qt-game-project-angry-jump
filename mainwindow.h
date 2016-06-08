#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMouseEvent>
#include <role.h>
#include <number.h>
#include <start.h>
#include <score.h>
#include <obstacle.h>
#include <floor.h>
#include <easymusic.h>
#include <jump.h>
#include <angry.h>
#include <thank_you.h>
#include <icon.h>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);    //繪製背景圖
    void mousePressEvent(QMouseEvent *event);	//滑鼠點下事件
    void keyPressEvent(QKeyEvent *event);	//鍵盤事件
    void keyReleaseEvent(QKeyEvent *event);	//鍵盤事件

private slots:
    void birdAction();			//鳥的動作
    void pipeAction();          //綠色管子的動作
    void floorAction();
    void startAction();
    void collisDete();			//碰撞偵測
private:
    void quit_game();
    void birdup();
    void createPipe();			// 產生水管
    void createBird();          // 產生角色 - 鳥
    void createFloor();
    void createStart();
    void createScore();
    void createHighScore();
    void createScoreObject();
    void createHighScoreObject();
    void gameLose();			 //遊戲結束
    void gameStart();			 //遊戲開始
    void gameRedy();             //遊戲預備

    void changeGap(int);
    ROLE *birds;			// 建立一隻角色 - 鳥
    FLOOR *floor;           // create a floor
    FLOOR *thank_you;
    FLOOR *angry;
    FLOOR *jump;
    FLOOR *icon;
    int icon_big;
    int quiting;
    double birdV;			// 鳥的速度
    QTimer *birdTimer;
    double timedata;			// birdTimer interval
    double floortimedata;
    double starttimedata;
    double scoretimedata;
    double birdV_array[15];
    int birdV_x;
    int birdV_y;
    double index_birdV;
    double bounce;
    int stage;
    int helping;
    int starting;
    enum{lose=0,start=1,redy=2};  // Enum三個參數, 代表遊戲狀態
    int gamemod;		//目前遊戲狀態, 0=lose, 1=start, 2=redy
    // 遊戲狀態預設流程： redy -> start -> lose -> redy -> start .... 不斷循環
    enum{pipeCount=5};		//  pipe 數量
    OBSTACLE *pipe[pipeCount];	// 建立水管
    QTimer *pipeTimer;
    QTimer *floorTimer;
    QTimer *scoreTimer;
    QTimer *beg_timer;
    int lue;     // pipeTimer interval
    int pipeXgap;		// 管子間距
    int lastPipe;		// the flag of rightest pipe
    int pipeTValue;
    int win_width;      // 視窗寬度
    int win_height;     // 視窗高度

    int start_game;
    int is_first;

    int cloud_width;
    int cloud_height;

    int fly;
    easyMusic *bgm;
    easyMusic *upm;
    easyMusic *crm;
    easyMusic *startm;


    START *play_sign;
    START *help_sign;
    START *quit_sign;
    NUMBER *score;
    NUMBER *highscore;
    SCORE *score_obj;
    SCORE *highscore_obj;


};

#endif // MAINWINDOW_H
