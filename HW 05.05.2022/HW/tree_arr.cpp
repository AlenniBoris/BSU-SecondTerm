#include "tree_arr.h"


void tree_arr::paintEvent(QPaintEvent *event) {
    QRect rect = this->rect();
    QPainter painter(this);
    QPen pen(Qt::red , 3);
    painter.setPen(pen);
    int mid = rect.width()/2;
    int leaf_rad = rect.height()/25 + rect.width()/25;
    this->draw(mid, leaf_rad, tree.turn_to_node(),painter,leaf_rad);
}

void tree_arr::draw(int X_cord, int Y_cord, Node* node, QPainter &painter, int l_r) {

    int dx = 0.4*l_r;
    int dy = 0.6*l_r;

    if (node == nullptr){
        return;
    } else{
        painter.drawEllipse(X_cord,Y_cord,l_r, l_r);
        painter.drawText(X_cord + dx, Y_cord + dy, QString::number(node->data));
    }
    if (node->left != nullptr){
        painter.drawLine(X_cord + dx, Y_cord + l_r, X_cord - 1.5*l_r, Y_cord + 2*l_r);
        draw(X_cord - 2*l_r, Y_cord + 2*l_r, node->left, painter, 0.7*l_r);
    }
    if (node->right != nullptr){
        painter.drawLine(X_cord + dx, Y_cord + l_r, X_cord + 2.5*l_r, Y_cord + 2*l_r);
        draw(X_cord + 2*l_r, Y_cord + 2*l_r, node->right, painter, 0.7*l_r);
    }

}
