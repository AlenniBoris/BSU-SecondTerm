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
    if ((event->buttons() & Qt::LeftButton)){
        QPointF point = event->pos();
        double x = point.rx() - width() / 2;
        lbl->setText(QString::number(-1*graph::func_culc(x / 33)));
        lbl->setGeometry(point.rx() + (QWidget::width() + QWidget::height()) / 180, point.ry() + (QWidget::width() + QWidget::height()) / 180, (QWidget::width() + QWidget::height()) / 36, (QWidget::width() + QWidget::height()) / 36);
    }
}

void mainwindow::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() & Qt::LeftButton){
        lbl->hide();
    }
}

