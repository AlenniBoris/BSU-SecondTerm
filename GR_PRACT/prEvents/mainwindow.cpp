#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QFile>
#include <QString>
#include <QFileDialog>

mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    layout = new QVBoxLayout(this);

    drawingPanel = new Widget(this);
    layout->addWidget(drawingPanel);

    dia = new QColorDialog(this);
    btn = new QPushButton("color", this);
    connect(btn, SIGNAL(clicked()), SLOT(btn_color()));
    layout->addWidget(btn);

    slider = new QSlider(Qt::Horizontal, this);
    label = new QLabel("0", this);
    layout->addWidget(label);
    label->setFixedSize(30,20);
    connect(slider, &QSlider::valueChanged, label,static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    connect(slider, SIGNAL(valueChanged(int)), SLOT(line_size()));
    layout->addWidget(slider);

}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::btn_color() {
    drawingPanel->setColor(QColorDialog::getColor());
}

void mainwindow::line_size() {
    drawingPanel->setWidth(slider->value());
}
