#ifndef HW_TREE_ARR_H
#define HW_TREE_ARR_H

#include <QWidget>
#include "BinSrchTreeARR.h"
#include <QPainter>

class tree_arr : public QWidget {
Q_OBJECT
private:

    BinSrchTreeARR tree;

public:
    tree_arr(BinSrchTreeARR treeArr) : tree(treeArr) {};
    ~tree_arr() {};

    void paintEvent(QPaintEvent *event);
    void draw(int X_cord,int Y_cord, Node* node, QPainter& painter, int l_r);

};


#endif //HW_TREE_ARR_H
