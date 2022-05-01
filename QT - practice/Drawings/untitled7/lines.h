#ifndef LINES_H
#define LINES_H


#include <QWidget>

class lines : public QWidget{
public :
    lines(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);
    void drawLines(QPainter *qp);
};

#endif // LINES_H
