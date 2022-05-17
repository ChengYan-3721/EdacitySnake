#include "Snake.h"

Snake::Snake(int x, int y, enum Type type) {
    setPos(x, y);
    setData(T0_type, type);
    switch (type) {
        case T1_food:
            setPixmap(QPixmap("./img/food.png"));
            break;
        case T3_body:
            setPixmap(QPixmap("./img/body.png"));
            break;
        default:
            break;
    }
}

//QPainterPath Snake::shape() const {
//    QPainterPath path;
//    path.addRect(7, 7, 18, 18);
//    return path;
//}

//QRectF Snake::boundingRect() const {
//    return QRectF(-12, -12, 25, 25);
//}
