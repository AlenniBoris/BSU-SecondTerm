#ifndef UNTITLED1_TREE_NODE_H
#define UNTITLED1_TREE_NODE_H

#include <QWidget>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include "BinSrchTree.h"
#include <cmath>

class Tree_n : public QWidget, public BinSrchTree{
Q_OBJECT

public:

    Tree_n(QWidget *parent = nullptr){};
    ~Tree_n(){};

private:
    void paintEvent(QPaintEvent *event);
    void draw(Node* t);
};


#endif //UNTITLED1_TREE_NODE_H
