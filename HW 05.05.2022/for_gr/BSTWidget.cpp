#include "BSTWidget.h"


BSTWidget::BSTWidget(QWidget *parent)
        : QWidget(parent),
          height(4)
{
    width = 8; // 2^(height-1)
}

void BSTWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QRect widgetRect = this->rect();
    int delta = 20;
    int radius = 15;
    int dy = (widgetRect.height() - 2 * delta) / (height - 1);
    int dx = (widgetRect.width() - 2 * delta) / (width - 1);
    QPen latticePen(QColor(200, 200, 10), 2, Qt::DotLine);
    QPen treePen(QColor(0, 0, 255), 3);
    QBrush treeBrush(Qt::gray);
    painter.setPen(latticePen);
    for (int i = 0; i < height; ++i) {
        painter.drawLine(delta, delta + i * dy, delta + (width - 1) * dx, delta + i * dy);
    }
    for (int i = 0; i < width; ++i) {
        painter.drawLine(delta + i * dx, delta, delta + i * dx, delta + (height - 1) * dy);
    }
    painter.setPen(treePen);
    painter.setBrush(treeBrush);
    for (int i = 0; i < width; i += 2) {
        painter.drawLine(delta + i * dx, delta + (height - 1) * dy, delta + (i + 0.5) *
                                                                            dx, delta + (height - 2) * dy);
        painter.drawLine(delta + (i + 0.5) * dx, delta + (height - 2) * dy, delta + (i
                                                                                     + 1) * dx,
                         delta + (height - 1) * dy);
        painter.drawEllipse(delta + (i + 0.5) * dx - radius, delta + (height - 2) * dy
                                                             - radius, 2 * radius, 2 * radius);
    }
    // draw leaves
    for (int i = 0; i < width; ++i) {
        painter.drawEllipse(delta + i * dx - radius, delta + (height - 1) * dy -
                                                     radius, 2 * radius, 2 * radius);
    }
}