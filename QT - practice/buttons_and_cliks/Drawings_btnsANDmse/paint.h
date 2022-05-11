//
// Created by User on 11.05.2022.
//

#ifndef DRAWINGS_BTNSANDMSE_PAINT_H
#define DRAWINGS_BTNSANDMSE_PAINT_H


#include <QWidget>
#include <QTimer>
#include <QResizeEvent>

#include "paintScene.h"



namespace Ui { class Paint; }


class Paint : public QWidget {
public:
    explicit Paint(QWidget *parent = 0);

    ~Paint();

private:
    Ui::Paint *ui;
    QTimer *timer;

    paintScene *scene;
private:
    void resizeEvent(QResizeEvent *event);
private slots:
    void slotTimer();
};


#endif //DRAWINGS_BTNSANDMSE_PAINT_H
