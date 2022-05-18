#include "slider.h"

#include <QVBoxLayout>

Slider::Slider(QWidget *parent) : QWidget(parent){
    QVBoxLayout *vbox = new QVBoxLayout(this);
//
//    slider = new QSlider(Qt::Vertical, this);
//    vbox->addWidget(slider);
//
//    label = new QLabel("0", this);
//    vbox->addWidget(label);
//
//    connect(slider, &QSlider::valueChanged, label,static_cast<void (QLabel::*)(int)>(&QLabel::setNum));

    slider = new QSlider(Qt::Horizontal, this);
    vbox->addWidget(slider);

    label = new QLabel("0", this);
    vbox->addWidget(label);

    connect(slider, &QSlider::valueChanged, label,static_cast<void (QLabel::*)(int)>(&QLabel::setNum));

}


