#include "tree_node.h"

void tree_node::paintEvent(QPaintEvent *event) {
    QRect rect = this->rect();
    QPainter painter(this);
    QPen pen(Qt::black, 3);
    QBrush brush(Qt::black);
    painter.setPen(pen);
    int mid = rect.width()/2;
    this->draw(mid, leaf_rad, tree.ret_node(), painter);
}

void tree_node::draw(int X_cord, int Y_cord, Node* node, QPainter &painter) {
    if (node == nullptr){
        return;
    } else{
        painter.drawEllipse(X_cord,Y_cord,leaf_rad, leaf_rad);
        painter.drawText(X_cord + 0.4*leaf_rad, Y_cord + 0.5*leaf_rad, QString::number(node->data));
    }
    if (node->left != nullptr){
        painter.drawLine(X_cord + 0.4*leaf_rad, Y_cord + leaf_rad, X_cord - 1.5*leaf_rad, Y_cord + 2*leaf_rad);
        draw(X_cord - 2*leaf_rad, Y_cord + 2*leaf_rad, node->left, painter);
    }
    if (node->right != nullptr){
        painter.drawLine(X_cord + 0.4*leaf_rad, Y_cord + leaf_rad, X_cord + 2.5*leaf_rad, Y_cord + 2*leaf_rad);
        draw(X_cord + 2*leaf_rad, Y_cord + 2*leaf_rad, node->right, painter);
    }
}


