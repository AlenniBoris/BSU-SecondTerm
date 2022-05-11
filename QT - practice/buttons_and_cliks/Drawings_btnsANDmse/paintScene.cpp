//
// Created by User on 11.05.2022.
//

#include "paintScene.h"
#include <QGraphicsSceneMouseEvent>

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               10,10,QPen(Qt::NoPen),QBrush(Qt::red));
    previousPoint = event->scenePos();
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::red, 5,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();
}
