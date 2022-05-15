//
// Created by User on 15.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBoxLayout>


mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    QBoxLayout* layout = new QVBoxLayout();
    f_graph = new graph(this);

    dialog_fx_btn =  new QPushButton("f(x)", this);
    connect(dialog_fx_btn, SIGNAL(clicked()), SLOT(f_btn_logic()));

    layout->addWidget(f_graph);
    layout->addWidget(dialog_fx_btn);

    f_wind = new f_x_mean();

    setLayout(layout);
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::f_btn_logic() {
    f_wind->show();
}

