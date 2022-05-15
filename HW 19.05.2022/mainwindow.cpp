#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBoxLayout>
#define PI 3.141592653589793

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

    lbl = new QLabel(this);

    setLayout(layout);


}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::f_btn_logic() {
    f_wind->show();
}

void mainwindow::mousePressEvent(QMouseEvent *event) {
    if(event->buttons() & Qt::LeftButton){
        lbl->show();
    }
}

void mainwindow::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && scribbling)
    {
        QPointF point = event->pos();
        lbl->setText(QString::number(graph::func_culc(event->x())));
        lbl->setGeometry(point.rx() + 10, point.ry() + 10, 50, 50);
    }
}

void mainwindow::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() & Qt::LeftButton && scribbling)
    {
        lbl->hide();
    }
}

