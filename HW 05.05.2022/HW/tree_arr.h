#ifndef HW_TREE_ARR_H
#define HW_TREE_ARR_H

#include <QWidget>
#include "N_MY_ARRTR.h"
#include <QPainter>

class Widget : public QWidget
{
Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget() {};

protected:
    void paintEvent(QPaintEvent* event);
private:
    ABST bst;
};


#endif //HW_TREE_ARR_H
