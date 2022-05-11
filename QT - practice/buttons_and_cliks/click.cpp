#include <QPainter>
#include "click.h"

click::click(QWidget *parent) : QWidget(parent) {
    QHBoxLayout *hbox = new QHBoxLayout(this);

    QPushButton *quitBtn = new QPushButton("Quit", this);


    hbox->addWidget(quitBtn,5,Qt::AlignCenter);

    connect(quitBtn, &QPushButton::pressed, qApp, &QApplication::quit);
}
