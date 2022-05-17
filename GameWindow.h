#pragma once

#include "ui_window.h"
#include "Snake.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QDateTime>
#include <QRandomGenerator>
#include <QList>
#include <QMessageBox>
#include <iostream>

class QMessageBox;

static int WIDTH = 500;
static int HEIGHT = 500;

class GameWindow: public QWidget {
Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow() override;
private:
    Ui::Form *ui;
    QGraphicsScene *scene;
    Snake* head;
    QList<Snake*> body;
    Snake* body0;
    Snake* body1;
    Snake* body2;
    Snake* tail;
    Snake* food;
    enum Move{Up, Down, Left, Right};
    Move orien;
    int score;
    QTimer* timer;
    enum State{start, pause, over};
    State state;

    void keyPressEvent(QKeyEvent *event) override;
    void resizeEvent(QResizeEvent*) override;
    void time_out();
public:
    void start_game();      //初始化游戏
    void add_food();        //生成食物
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void move_body();
    void crash_monitor();
    void add_len();
    void game_pause();
    void restart();
};
