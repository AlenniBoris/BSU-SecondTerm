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

double graph::func_culc(double x){
    double f_x = -(pow(x,2) + sin(x));
    return f_x;
}

void graph::paintEvent(QPaintEvent *event) {

    delta = 0.5;
    x_beg = -30;
    x_end = 30;

    int margin = 20;

    QPainter painter(this);

    QRect qRect;

    QPoint originOfCoordinates(QWidget::width() / 2, QWidget::height()/2 );  // Определяем новое начало координат
    painter.translate(originOfCoordinates);

    QBrush pts_bsh(Qt::white);
    QPen pts_pen(pts_bsh, 3);

    QBrush line_bsh(Qt::darkGray);
    QPen line_pen(line_bsh, 3);

    for (x = x_beg; x <= x_end; x += delta) {
        QPoint point;
        point.setX(x);
        point.setY(func_culc(x));
        pts.push_back(point);
    }

    for (int i = 0; i < pts.size()-1; ++i) {
        painter.setPen(line_pen);
        painter.drawLine(pts[i], pts[i+1]);
        painter.setPen(pts_pen);
        painter.drawLine(pts[pts.size()-1], pts[0]);
    }



}


