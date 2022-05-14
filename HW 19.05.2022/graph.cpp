//
// Created by User on 14.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_graph.h" resolved

#include "graph.h"
#include "ui_graph.h"


graph::graph(QWidget *parent) :
        QWidget(parent), ui(new Ui::graph) {
    ui->setupUi(this);

}

graph::~graph() {
    delete ui;
}

double graph::func_culc(int x){
    double f_x = -(pow(x,2) + sin(x));
    return f_x;
}

void graph::paintEvent(QPaintEvent *event) {

    delta = 0.05;

    int margin = 20;

    QPainter painter(this);

    QRect qRect;

    int mid_x = QWidget::width() / 2;
    int mid_y = QWidget::height() / 2;
    QPoint center(mid_x, mid_y);  // Определяем новое начало координат
    painter.translate(center);

    int dx = (QWidget::width()-margin)/20;
    int dy = (QWidget::height()-margin)/20;

    QBrush axis_bsh(Qt::black);
    QPen axis_pen(axis_bsh, 2);
    painter.setPen(axis_pen);

    for (int i = -20; i < 20; ++i) {

        painter.drawLine(i*dx,dy/20, i*dx, -dy/20); // штрихи для x
        painter.drawText(i*dx, dy/5, QString::number(i));// штрихи для y
        painter.drawLine(dx/20, i*dy, -dx/20, i*dy);// текст для х
        if (i == 0){ continue; }
        painter.drawText(-dx/5, i*dy, QString::number(i));

        painter.drawLine(-2*mid_x, 0, 2*mid_x, 0);
        painter.drawLine(0, -2*mid_y, 0, 2*mid_y);

    }

    QBrush pts_bsh(Qt::white);
    QPen pts_pen(pts_bsh, 3);

    QBrush line_bsh(Qt::blue);
    QPen line_pen(line_bsh, 3);

    for (int i = -3; i < 3; ++i) {
        QPointF point;
        point.setX(i*dx);
        point.setY(20*func_culc(i));
        pts.push_back(point);
        x = x + delta;
    }

    for (int i = 0; i < pts.size()-1; ++i) {
        painter.setPen(line_pen);
        painter.drawLine(pts[i], pts[i+1]);
        painter.setPen(pts_pen);
//        painter.drawLine(pts[pts.size()-1], pts[0]);
    }

}


