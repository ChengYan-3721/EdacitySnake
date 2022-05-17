#pragma once

#include <QGraphicsPixmapItem>


class Snake : public QGraphicsPixmapItem {
public:

    enum Type{T0_type, T1_food, T2_head, T3_body};

    Snake(int x, int y, enum Type type);

//    QPainterPath shape() const override;
//    QRectF boundingRect() const override;
};

