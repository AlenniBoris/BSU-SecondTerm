//
// Created by User on 11.05.2022.
//

#ifndef DRAWINGS_BTNSANDMSE_PAINTSCENE_H
#define DRAWINGS_BTNSANDMSE_PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>


class paintScene : public QGraphicsScene{
public:
    explicit paintScene(QObject *parent = 0) : QGraphicsScene(parent){};
    ~paintScene(){};

private:
    QPointF previousPoint;
private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};


#endif //DRAWINGS_BTNSANDMSE_PAINTSCENE_H
