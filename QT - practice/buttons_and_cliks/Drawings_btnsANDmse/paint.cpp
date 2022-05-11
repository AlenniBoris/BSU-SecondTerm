//
// Created by User on 11.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Paint.h" resolved

#include "paint.h"
#include "ui_Paint.h"
#include <QGraphicsView>

Paint::Paint(QWidget *parent) : QWidget(parent), ui(new Ui::Paint) {

    ui->setupUi(this);

    scene = new paintScene();

    ui->graphicsView->setScene(scene);

    timer = new QTimer();

    connect(timer, &QTimer::timeout, this, &Paint::slotTimer);
    timer->start(100);
}

Paint::~Paint()
{
    delete ui;
}

void Paint::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void Paint::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}
