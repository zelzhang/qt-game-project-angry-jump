#include "mainwindow.h"
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
const int multiplierForAxis = 2;
char* convertStringToCharPointer(std::string str);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    win_width = 380;
    win_height = 500;
    this->setFixedSize(win_width,win_height);
    this->setWindowIcon(QIcon(":/Image/bird1.png"));
    this->setWindowTitle("Angry Jump");
    setMouseTracking(true);

    for(int i=0;i<pipeCount;i++){
        pipe[i]=new OBSTACLE(this);
    }
    cloud_width = pipe[0]->getW();
    cloud_height = pipe[0]->getH();

    birds=new ROLE(this);
    play_sign = new START(this);
    help_sign = new START(this);
    quit_sign = new START(this);
    bgm = new easyMusic((char*)"Media/bgmusic.mp3", 80, 1);
    upm = new easyMusic((char*)"Media/upm.wav", 80, 0);
    crm = new easyMusic((char*)"Media/crm.wav", 80, 0);
    startm = new easyMusic((char*)"Media/startmusic.mp3", 80, 1);
    floor = new FLOOR(this);
    score = new NUMBER(this);
    highscore = new NUMBER(this);
    score_obj = new SCORE(this);
    highscore_obj = new SCORE(this);
    angry = new FLOOR(this);
    jump = new FLOOR(this);
    thank_you = new FLOOR(this);
    icon = new FLOOR(this);
    is_first = 1;
    starting = 1;
    quiting = 0;
    gameRedy();

}
void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap bgImg;
    bgImg.load(":/Image/bg.jpg");
    painter.drawPixmap(0,0,win_width, win_height, bgImg);

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(start_game == 0){
        if(event->pos().y() >= 100 && event->pos().y() <= 175 && stage == 0){
                upm->play();
                start_game = 1;

                startm->stop();
                bgm->play();
            }else if(event->pos().y() >= 200 && event->pos().y() <= 275 && stage == 1){
                helping = 1;
            }else if(event->pos().y() >= 300 && event->pos().y() <= 375 && stage == 2){
                quit_game();
            }else if(event->pos().y() >= 100 && event->pos().y() <= 175)
                stage = 0;
            else if(event->pos().y() >= 200 && event->pos().y() <= 275)
                stage = 1;
            else if(event->pos().y() >= 300 && event->pos().y() <= 375)
                stage = 2;

    }


}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(starting == 1){
        starting = 0;
    }else if(start_game == 1){
        if(event->key() == Qt::Key_Left){
            birdV_x = -3;
        }
        else if(event->key() == Qt::Key_Right){
            birdV_x = 3;
        }
    }
    else if(helping == 0){
        if(event->key() == Qt::Key_Space){
            if(helping == 1){
                helping = 0;
            }else if(stage == 0){
                upm->play();
                start_game = 1;

                startm->stop();
                bgm->play();
            }else if(stage == 1){
                helping = 1;
            }else if(stage == 2){
                quit_game();
            }

        }else if(event->key() == Qt::Key_Up){
            if(stage == 0){
                ;
            }else if(stage == 1){
                stage = 0;
            }else if(stage == 2){
                stage = 1;
            }

        }else if(event->key() == Qt::Key_Down){
            if(stage == 0){
                stage = 1;
            }else if(stage == 1){
                stage = 2;
            }else if(stage == 2){
                ;
            }

        }
    }else if(helping == 1){
        helping = 0;
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{

    birdV_x = 0;
}
void MainWindow::createScore(){
    score->move(win_width-3*score->wid, 0);
    if(is_first == 1) {
        scoreTimer =new QTimer(this);
        connect(scoreTimer,SIGNAL(timeout()),this,SLOT(update()));
        scoretimedata = 8;
    }

}
void MainWindow::createHighScore(){
    highscore->move(win_width-3*score->wid, score->hei);
}
void MainWindow::createScoreObject(){
    score_obj->change_type('s');
    score_obj->wid /=2;
    score_obj->move(win_width-score_obj->wid-3*score->wid-score_obj->error, score_obj->error);
}
void MainWindow::createHighScoreObject(){
    highscore_obj->change_type('h');
    highscore_obj->move(win_width-highscore_obj->wid-3*score->wid-highscore_obj->error, score->hei + highscore_obj->error);
}
void MainWindow::createPipe()
{
    fly = 1;
    birds->falling = 0;

    int pipR;
    qsrand(time(NULL));

    for(int i=0;i<pipeCount;i++)
    {
        pipR=qrand()%200;
        pipeXgap=pipe[i]->getG();
        pipe[i]->move(pipR,-i*pipeXgap-pipe[i]->getH());
        pipe[i]->setP(i,0);
    }

    if(is_first == 1) {
        pipeTimer =new QTimer(this);
        connect(pipeTimer,SIGNAL(timeout()),this,SLOT(pipeAction()));
        connect(pipeTimer,SIGNAL(timeout()),this,SLOT(collisDete()));
        pipeTValue=8;
    }




}
void MainWindow::createStart()
{


    play_sign->change_type(0);
    help_sign->change_type(1);
    quit_sign->change_type(2);



    if(is_first == 1) {
        beg_timer =new QTimer(this);
        connect(beg_timer,SIGNAL(timeout()),this,SLOT(update()));
        connect(beg_timer,SIGNAL(timeout()),this,SLOT(startAction()));
        starttimedata=8;
    }

}
void MainWindow::startAction(){



    if(start_game == 0 && helping == 0 && starting == 0 && quiting == 0){
        if(stage == 0){
            play_sign->activate();
            help_sign->disable();
            quit_sign->disable();
            birds->move(60,115);
        }else if(stage == 1){
            play_sign->disable();
            help_sign->activate();
            quit_sign->disable();
            birds->move(60,215);
        }else{
            play_sign->disable();
            help_sign->disable();
            quit_sign->activate();
            birds->move(60,315);
        }
        play_sign->move(150,100);
        help_sign->move(150,200);
        quit_sign->move(150,300);
    }else if(helping == 1 && starting == 0 && quiting == 0){
        play_sign->move(700,700);
        help_sign->move(700,700);
        quit_sign->move(700,700);
        birds->move(60,215);
    }else{
        play_sign->move(700,700);
        help_sign->move(700,700);
        quit_sign->move(700,700);
    }

}
void MainWindow::createFloor()
{

    floor->status = 0;
    floor->move(1000, 1000);
    angry->status = 1;
    jump->status = 2;
    thank_you->status = 3;
    icon->status = 4;
    icon->size = 30;
    angry->move(100,-100);
    jump->move(100,500);
    thank_you->move(100,-130);
    icon->move(30,50);
    icon_big = 1;
    icon->size = 32;

    if(is_first == 1){
        floorTimer =new QTimer(this);
        connect(floorTimer,SIGNAL(timeout()),this,SLOT(floorAction()));
        floortimedata=8;
    }

}
void MainWindow::floorAction()
{

    if(starting == 1){
        if(angry->pos().y() < 150) angry->move(angry->pos().x(), angry->pos().y()+1);
        if(jump->pos().y() > 250) jump->move(jump->pos().x(), jump->pos().y()-1);
        if(icon->size == 120) icon_big = 0;
        else if(icon->size == 30) icon_big = 1;
        if(icon_big == 1) icon->size += 1;
    }else{
        angry->move(0,1000);
        jump->move(0,-1000);
        icon->move(1000,1000);
        if(quiting == 0) icon->size = 30;
    }
    if(quiting == 1){
        if(thank_you->pos().y() < 200) thank_you->move(thank_you->pos().x(), thank_you->pos().y()+1);
        icon->move(30,50);
        if(icon->size <= 100) icon->size += 3;
    }
    if(helping == 0 || start_game == 1) floor->move(1000,1000);
    else floor->move(0,0);

}

void MainWindow::pipeAction()
{
    int pipR;
    if(pipe[pipeCount-1]->pos().y() > 0){
        fly = 0;
    }
    if(start_game == 0);
    else{
        for(int i=0;i<pipeCount;i++)
        {
            if(fly == 1) pipe[i]->move(pipe[i]->pos().x(), pipe[i]->pos().y()+2);
            else pipe[i]->move(pipe[i]->pos().x(), pipe[i]->pos().y()-birdV);
            pipe[i]->move(pipe[i]->pos().x(),pipe[i]->pos().y()+1);

            if(pipe[i]->pos().y()>win_height+10)
            {
                pipR=qrand()%200 ;
                pipe[i]->move(pipR,-20);
                if(score->data >= 150) pipe[i]->setW(30);
                else if(score->data >= 100) pipe[i]->setW(50);
                else if(score->data >= 50) pipe[i]->setW(70);
                if(score->data < 100)pipe[i]->setP(pipR+score->data+pipe[i]->pos().y(), 0);
                else pipe[i]->setP(pipR+score->data+pipe[i]->pos().y(), 1);
                score->data++;
            }
        }
    }

    if(pipe[0]->pos().y() < -300){
        birdV_y = 2;
    }
    if(birds->pos().y() >= win_height){

        if(birds->crashing == 0) crm->play();
        birdTimer->stop();
        floorTimer->stop();
        gameLose();

    }
}
void MainWindow::createBird(){

    birds->move(60,250);
    this->birdV_x = 0;
    this->birdV_y = 0;

    this->birdV_array[0]=-3;
    this->birdV_array[1]=-4;
    this->birdV_array[2]=-3;
    this->birdV_array[3]=-2;
    this->birdV_array[4]=-1;
    this->birdV_array[5]=-1;
    this->birdV_array[6]=-1;
    this->birdV_array[7]=0;
    this->birdV_array[8]=1;
    this->birdV_array[9]=1;
    this->birdV_array[10]=2;
    this->birdV_array[11]=2;
    this->birdV_array[12]=2;
    this->birdV_array[13]=3;
    this->birdV_array[14]=3;
    for(int i=0; i<14; i++) this->birdV_array[i] *= multiplierForAxis;

    this->index_birdV=0;

    bounce = 0.0;
    birdV=0;

    if(is_first == 1){
        birdTimer=new QTimer(this);
        connect(birdTimer,SIGNAL(timeout()),this,SLOT(birdAction()));
        connect(birdTimer,SIGNAL(timeout()),this,SLOT(update()));
        timedata=8;
    }
}
void MainWindow::birdup(){

    index_birdV=0.0;
    birdV=birdV_array[int(index_birdV)];
}

void MainWindow::birdAction()
{
    if(starting == 1 || quiting == 1) birds->move(-100,-100);
    else if(birds->x() <= win_width && birdV_x >= 0)birds->move(birds->x()+birdV_x, birds->y()+birdV_y);
    else if(birds->x() >= 0 && birdV_x <= 0)birds->move(birds->x()+birdV_x, birds->y()+birdV_y);
    else birds->move(birds->x(), birds->y()+birdV_y);

    if(start_game == 0)
        index_birdV = 7;
    else if(index_birdV >= 1.0 && bounce > 0){
        bounce -= 0.1;
        upm->play();
    }
    else if(index_birdV<14.0)
        index_birdV+=0.1;
    else
        index_birdV=14.0;

    if(start_game == 0)
        birds->falling = 0;
    else if(index_birdV > 7.0)
        birds->falling = 1;
    else
        birds->falling = 0;

    birdV=birdV_array[int(index_birdV)];

    if(score->data > 100){
        this->birdV_array[8]=2;
        this->birdV_array[9]=2;
        this->birdV_array[10]=4;
        this->birdV_array[11]=4;
        this->birdV_array[12]=5;
        this->birdV_array[13]=6;
        this->birdV_array[14]=7;
    }else if(score->data > 50){
        this->birdV_array[8]=1;
        this->birdV_array[9]=2;
        this->birdV_array[10]=2;
        this->birdV_array[11]=3;
        this->birdV_array[12]=3;
        this->birdV_array[13]=4;
        this->birdV_array[14]=4;
    }

}

void MainWindow::collisDete()
{

    int birdLx=birds->pos().x();
    int birdRx=birds->pos().x()+30;
    int birdDy=birds->pos().y()+30;
    for(int i=0;i<pipeCount;i++)
    {

        if(birds->falling && birdLx <= pipe[i]->pos().x()+pipe[i]->getW() && birdRx >= pipe[i]->pos().x())
        {
            if(fly == 0 && birds->falling && birdDy >= pipe[i]->pos().y() && birdDy <= pipe[i]->pos().y()+10){
                if(pipe[i]->getP() == 0){
                    birdup();
                    upm->play();
                }else if(pipe[i]->getP() == 1){
                    birdup();
                    upm->play();
                    pipe[i]->move(1000,pipe[i]->pos().y());
                }else if(pipe[i]->getP() == 2){
                    birdup();
                    upm->play();
                    bounce = 10.0;
                }

            }

        }
    }
}
void MainWindow::gameRedy()
{
    start_game = 0;
    gamemod=redy;
    startm->play();
    createFloor();
    createBird();
    createPipe();
    createStart();

    createScore();
    createHighScore();
    createScoreObject();
    createHighScoreObject();

    FILE* score_record = fopen("highscore.log", "r");
    fscanf(score_record, "%d", &highscore->data);
    fclose(score_record);
    birds->crashing = 0;
    stage = 0;
    helping = 0;
    quiting = 0;
    gameStart();
}
void MainWindow::gameLose()
{
    bgm->stop();
    startm->play();
    gamemod=lose;
    pipeTimer->stop();
    floorTimer->stop();
    if(score->data > highscore->data) highscore->data = score->data;
    FILE* score_record = fopen("highscore.log", "w");
    fprintf(score_record, "%d", highscore->data);
    fclose(score_record);
    score->data = 0;
    stage = 0;
    helping = 0;
    quiting = 0;
    //sleep(3000);
    is_first = 0;

    gameRedy();
}
void MainWindow::gameStart()
{
    gamemod=start;
    start_game = 0;
    birdTimer->start(timedata);
    floorTimer->start(floortimedata);
    pipeTimer->start(pipeTValue);
    beg_timer->start(starttimedata);
    scoreTimer->start(scoretimedata);
}
void MainWindow::quit_game(){
    if(quiting == 0) {
        quiting = 1;
        icon->size = 30;
    }
    else exit(0);
}
