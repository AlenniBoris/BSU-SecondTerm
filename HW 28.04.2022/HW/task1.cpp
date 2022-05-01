#include "task1.h"

#include <QPainter>

using namespace std;

void MyWidget::paintEvent(QPaintEvent *event) {
 Q_UNUSED(event);

 QRect widgetRect = this->rect();
 QPainter painter(this);
 QPen pen(Qt::blue, 2.5);
 QBrush brush(Qt::gray);

 painter.setPen(pen);
 painter.setBrush(brush);

 int max = *(std::max_element(data.begin(), data.end()));
 int dx = widgetRect.width() / data.size();
 int dy = widgetRect.height() / max;

 for (int i = 0; i < data.size(); i++)
 {
     painter.drawRect(i * dx, widgetRect.height() - data[i]*dy, dx,data[i] * dy);
     QString str = QString::number(data[i]);
     painter.drawText(i * dx + dx / 2 ,widgetRect.height()-(0.5*dx), str);
 }
}
