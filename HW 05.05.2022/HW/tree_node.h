#ifndef HW_TREE_NODE_H
#define HW_TREE_NODE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QString>
#include "BinSrchTree.h"


class tree_node : public QWidget {
Q_OBJECT
private:
    BinSrchTree tree;
//    int leaf_rad = 100;
public:
    tree_node(BinSrchTree btree) : tree(btree){};
    ~tree_node(){};

    void paintEvent(QPaintEvent *event);
    void draw(int X_cord,int Y_cord, Node* node, QPainter& painter, int l_r);
};


#endif //HW_TREE_NODE_H
