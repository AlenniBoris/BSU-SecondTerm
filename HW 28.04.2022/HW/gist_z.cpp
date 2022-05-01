#include "gist_z.h"

#include <QPainter>
#include <cmath>

using namespace std;

Gist_z::Gist_z(QWidget *parent) : QWidget(parent){
    for(int i = -5 ; i < 5; i++){
        data.push_back(rand() % 10 - 5);
    }
};


void Gist_z::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QRect widgetRect = this->rect();
    QPainter painter(this);
    QPen pen(Qt::blue, 2.5);
    QBrush brush(Qt::gray);

    painter.setBrush(brush);
    painter.setPen(pen);

    int min = *(min_element(data.begin(), data.end()));
    int max = *(max_element(data.begin(), data.end()));
    int dx = widgetRect.width() / data.size();
    int dy = widgetRect.height() / min;


    for(int i = 0; i < data.size(); ++i){
        painter.drawRect(i * dx, widgetRect.height()/2, dx,data[i] * dy);
        QString str = QString::number(data[i]);
        painter.drawText(i * dx + dx / 2 ,(widgetRect.height()/2), str);
    }
}
