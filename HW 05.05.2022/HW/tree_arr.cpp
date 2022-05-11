#include "tree_arr.h"


Widget::Widget(QWidget* parent)
        : QWidget(parent)
{
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);
    bst.traverse();
}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    int x = width() / 2;
    int y = 40;
    int dx = width() / 2;
    int dy = height() / 8;
    int index = 0;
    int radius = 20;
    int level = 1;
    int count = 1;
    int curX, curY;
    int size = width() / 70;
    QPen pen(Qt::black, 3);
    QBrush brush(Qt::gray);
    painter.setBrush(brush);

    painter.setFont(QFont("arial", size));
    while (level != 6)
    {
        curX = x;
        curY = y;
        for (int i = 0; i < count; ++i)
        {
            if (bst.arr[index] != -1)
            {
                if (bst.arr[2 * index + 1] != -1)
                    painter.drawLine(curX, curY, curX - dx / 2, curY + dy);
                if (bst.arr[2 * index + 2] != -1)
                    painter.drawLine(curX, curY, curX + dx / 2, curY + dy);
                painter.drawEllipse(curX - radius, curY - radius, 2 * radius, 2 * radius);
                QString str = QString::number(bst.arr[index]);
                painter.drawText(curX - size / 2 - ((str.length() - 1) * radius) / 2 + ((str.length() - 1) * (radius / 2)), curY + size / 2, str);
            }
            ++index;
            curX += 2 * dx;
        }
        ++level;
        y += dy;
        x /= 2;
        count *= 2;
        dx /= 2;
    }
}
