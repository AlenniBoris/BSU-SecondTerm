//
// Created by User on 11.05.2022.
//

#include "Timer.h"

#include <QHBoxLayout>
#include <QTime>

void Timer::timerEvent(QTimerEvent *e) {
    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString();

    label->setText(stime);
}

Timer::Timer(QWidget *parent) : QWidget(parent) {
    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->setSpacing(5);

    label = new QLabel("", this);
    hbox->addWidget(label, 0, Qt::AlignCenter);

    QTime qtime = QTime::currentTime();
    QString stime = qtime.toString();
    label->setText(stime);

    startTimer(1000);
}
