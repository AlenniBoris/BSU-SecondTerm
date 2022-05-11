//
// Created by User on 11.05.2022.
//

#ifndef BUTTONS_AND_CLIKS_TIMER_H
#define BUTTONS_AND_CLIKS_TIMER_H

#include <QWidget>
#include <QApplication>
#include <QLabel>

class Timer : public QWidget{
public:
    Timer(QWidget *parent = 0);
protected:
    void timerEvent(QTimerEvent *e);

private:
    QLabel *label;
};


#endif //BUTTONS_AND_CLIKS_TIMER_H
