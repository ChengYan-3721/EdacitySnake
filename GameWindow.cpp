#include "GameWindow.h"

GameWindow::GameWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Form),
        scene(new QGraphicsScene(this)),
//        head(new Snake(0, 0, Snake::T2_head)),
//        food(new Snake(0, 0, Snake::T1_food)),
        timer(new QTimer(this))
{
    ui->setupUi(this);
    setWindowOpacity(0.8);
    //设置场景大小
    scene->setSceneRect(0, 0, 1920, 1080);
    scene->setBackgroundBrush(Qt::black);   //设置背景为黑色

    start_game();

    //将场景添加到视图中
    ui->view->setScene(scene);
    ui->view->setSceneRect(0, 0, WIDTH, HEIGHT);
    ui->view->setStyleSheet("border:0px");      //设置视图边框为0
    ui->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //隐藏水平滚动条
    ui->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //隐藏垂直滚动条
    ui->view->setParent(this);      //设置父类（要在哪个窗口上显示）

    connect(timer, &QTimer::timeout, this, &GameWindow::time_out);
    connect(ui->pause, &QPushButton::clicked, this, &GameWindow::game_pause);
    connect(ui->restart, &QPushButton::clicked, this, &GameWindow::restart);
}

void GameWindow::start_game() {
    int x = QRandomGenerator::global()->bounded(WIDTH / 25) * 25;
    int y = QRandomGenerator::global()->bounded(HEIGHT / 25) * 25;
    head = new Snake(x, y, Snake::T2_head);
    body0 = new Snake(0, 0, Snake::T3_body);
    body1 = new Snake(0, 0, Snake::T3_body);
    body2 = new Snake(0, 0, Snake::T3_body);
    switch (QRandomGenerator::global()->bounded(4)) {   //随机生成方向
        case 0:
            head->setPixmap(QPixmap("./img/up.png"));
            orien = Up;
            body0->setPos(head->x(), head->y() + 25);
            body1->setPos(head->x(), head->y() + 50);
            body2->setPos(head->x(), head->y() + 75);
            break;
        case 1:
            head->setPixmap(QPixmap("./img/down.png"));
            orien = Down;
            body0->setPos(head->x(), head->y() - 25);
            body1->setPos(head->x(), head->y() - 50);
            body2->setPos(head->x(), head->y() - 75);
            break;
        case 2:
            head->setPixmap(QPixmap("./img/left.png"));
            orien = Left;
            body0->setPos(head->x() + 25, head->y());
            body1->setPos(head->x() + 50, head->y());
            body2->setPos(head->x() + 75, head->y());
            break;
        case 3:
            head->setPixmap(QPixmap("./img/right.png"));
            orien = Right;
            body0->setPos(head->x() - 25, head->y());
            body1->setPos(head->x() - 50, head->y());
            body2->setPos(head->x() - 75, head->y());
            break;
    }
    body << body0 << body1 << body2;
    scene->addItem(head);
    scene->addItem(body0);
    scene->addItem(body1);
    scene->addItem(body2);
    add_food();
    score = 0;
    state = start;
    ui->pause->setText("暂停");
    timer->start(1000 / (ui->speed->value() * 5));
}

//生成食物
void GameWindow::add_food() {
    int x, y;
    bool lap;
    do {
        lap = false;     //每次循环开始初始化为 false，之前把false放在上面了，找了好久的BUG才找到是这里的原因
        x = QRandomGenerator::global()->bounded(WIDTH / 25) * 25;
        y = QRandomGenerator::global()->bounded(HEIGHT / 25) * 25;
        //判断生成的位置是否蛇身和蛇尾有重叠
        for (const auto &item: body){
            if(item->x() == x && item->y() == y){
                lap = true;
                break;          //只要有一个重叠就直接结束for循环，重新生成随机数
            }
        }
        if (head->x() == x && head->y() == y) lap = true;
    } while (lap);
    food = new Snake(x, y, Snake::T1_food);
    scene->addItem(food);
}

void GameWindow::move_up() {
    move_body();
    if(head->y() - 25 < 0) head->setPos(head->x(), HEIGHT);
    head->moveBy(0, -25);
    head->setPixmap(QPixmap("./img/up.png"));
    orien = Up;
}

void GameWindow::move_down() {
    move_body();
    if(head->y() + 30 > HEIGHT) head->setPos(head->x(), -25);
    head->moveBy(0, 25);
    head->setPixmap(QPixmap("./img/down.png"));
    orien = Down;
}

void GameWindow::move_left() {
    move_body();
    if(head->x() - 25 < 0) head->setPos(WIDTH, head->y());
    head->moveBy(-25, 0);
    head->setPixmap(QPixmap("./img/left.png"));
    orien = Left;
}

void GameWindow::move_right() {
    move_body();
    if(head->x() + 30 > WIDTH) head->setPos(-25, head->y());
    head->moveBy(25, 0);
    head->setPixmap(QPixmap("./img/right.png"));
    orien = Right;
}

void GameWindow::move_body() {
    //把尾巴指针先保存，然后删除尾巴，改一下位置插入到最前面
    tail = body.at(body.length() - 1);
    body.remove(body.length() - 1);
    tail->setPos(head->x(), head->y());
    body.insert(0, tail);
    tail = nullptr;
}

void GameWindow::keyPressEvent(QKeyEvent *event) {
    //控制按键频率
//    static QDateTime clickLastTime;
//    QDateTime curDataTime = QDateTime::currentDateTime();
//    if(clickLastTime.addMSecs(1000 / (ui->speed->value() * 5) - 20) > curDataTime) return;
//    clickLastTime = curDataTime;
    switch (event->key()) {
        case Qt::Key_W:
        case Qt::Key_Up:
            if (orien != Down && !state) move_up();
            break;
        case Qt::Key_S:
        case Qt::Key_Down:
            if (orien != Up && !state) move_down();
            break;
        case Qt::Key_A:
        case Qt::Key_Left:
            if (orien != Right && !state) move_left();
            break;
        case Qt::Key_D:
        case Qt::Key_Right:
            if (orien != Left && !state) move_right();
            break;
        case Qt::Key_Space:
            game_pause();
            break;
    }
    crash_monitor();
}

void GameWindow::resizeEvent(QResizeEvent *) {
    WIDTH = ui->view->width();
    HEIGHT = ui->view->height();
    ui->view->setSceneRect(0, 0, WIDTH, HEIGHT);
    ui->view->resize(WIDTH/25*25, HEIGHT/25*25);
    resize(WIDTH/25*25, HEIGHT/25*25+50);
}

void GameWindow::time_out() {
    switch (orien) {
        case Up:
            move_up();
            break;
        case Down:
            move_down();
            break;
        case Left:
            move_left();
            break;
        case Right:
            move_right();
            break;
    }
    crash_monitor();
}

void GameWindow::crash_monitor() {
    QList collisions = head->collidingItems();
    for (const auto &item: collisions){
        if (item->data(Snake::T0_type) == Snake::T1_food) {
            scene->removeItem(food);
            delete food;
            food = nullptr;
            add_food();
            add_len();
            continue;
        }
        if (item->data(Snake::T0_type) == Snake::T3_body) {
            state = over;
            game_pause();
        }
    }
}

void GameWindow::add_len() {
    tail = new Snake(body.at(0)->x(), body.at(0)->y(), Snake::T3_body);
    body << tail;
    scene->addItem(tail);
    tail = nullptr;
    score++;
    ui->score->setNum(score);
}

void GameWindow::game_pause() {
    switch (state) {
        case start:
            timer->stop();
            state = pause;
            ui->pause->setText("继续");
            break;
        case pause:
            timer->start(1000 / (ui->speed->value() * 5));
            state = start;
            ui->pause->setText("暂停");
            break;
        default:
            timer->stop();
            QMessageBox::about(this, "提示", QString(" Game Over ! \n     得分 %1").arg(score));
            break;
    }

}

void GameWindow::restart() {
    timer->stop();
    if(head != nullptr) {
        scene->removeItem(head);
        delete head;
        head = nullptr;
    }
    qDeleteAll(body);
    body.clear();
    body0 = nullptr;
    body1 = nullptr;
    body2 = nullptr;
    tail = nullptr;
    if(food == nullptr) {
        scene->removeItem(food);
        delete food;
        food = nullptr;
    }
    scene->clear();
    start_game();
}

GameWindow::~GameWindow() {
    delete ui;
    delete scene;
    delete head;
    qDeleteAll(body);
    body.clear();
    delete food;
}
