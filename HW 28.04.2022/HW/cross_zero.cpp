#include "cross_zero.h"

using namespace std;

QString draw_el(int num_){
    if(num_ == 0){
        return "0";
    }
    if(num_ == 1){
        return "X";
    }
    if(num_ == -1){
        return "";
    }
    return "";
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
            qp.drawText(i*dx + 0.55*dx - 0.3*size,j*dy + 0.35*dy + 0.45*size ,draw_el(data[j][i]));
        }
    }
}
