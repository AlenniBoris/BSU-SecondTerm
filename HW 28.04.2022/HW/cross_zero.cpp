#include "cross_zero.h"

using namespace std;

void draw_el(int num_, QPainter& painter, int i, int j, double dx, double dy, double size){
    if(num_ == 0){
        QPen pen(Qt::red, 3);
        painter.setPen(pen);
        painter.drawEllipse((i+0.05)*dx,(j+0.05)*dy, 0.9*dx, 0.9*dy);
    }
    if(num_ == 1){
        QPen pen(Qt::blue, 3);
        painter.setPen(pen);
        painter.drawLine((i+0.1)*dx, (j+0.1)*dy, (i+0.9)*dx, (j+0.9)*dy);
        painter.drawLine((i+0.9)*dx, (j+0.1)*dy, (i+0.1)*dx, (j+0.9)*dy);
    }
}

void Cross_zero::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter qp(this);
    QRect widgetRect = this->rect();

    QPen pen(Qt::black, 2);
    qp.setPen(pen);
    int dx = widgetRect.width()/data.size();
    int dy = widgetRect.height()/data.size();
    for(int i = 1; i < data.size(); ++i){
      qp.drawLine(i*dx, 0, dx*i, widgetRect.height());
      qp.drawLine(0,i*dy, widgetRect.width(), i*dy);
    }
    int size = widgetRect.height() / 10;
    for(int i = 0; i<data.size(); ++i){
        for(int j = 0; j < data.size(); ++j){
            draw_el(data[i][j], qp, i, j ,dx, dy, size);
            //qp.drawText(i*dx + 0.55*dx - 0.3*size,j*dy + 0.35*dy + 0.45*size ,draw_el(data[j][i], qp));
        }
    }
}
