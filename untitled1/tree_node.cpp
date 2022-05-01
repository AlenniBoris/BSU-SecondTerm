#include "tree_node.h"
#define PI 3.14159265
void Tree_n::draw(BinSrchTree::Node *t) {
    QPainter painter_(this);
    QRect widgetRect = this->rect();
    int rad_ = 10;
    int ch_x = tan(45.0 * PI / 180) * rad_;
    QChar str = t->data;
    int i = 0;
    QPoint center(widgetRect.width() / 2 + (i - 1) * ch_x, rad_ * (i+1));
    QPoint r_center(widgetRect.width() / 2 + i * ch_x, rad_ * (i + 1));
    QPoint l_center(widgetRect.width() / 2 - i * ch_x, rad_ * (i + 1));

    painter_.drawEllipse(center, rad_, rad_);
    painter_.drawText(center, str);

//        if (t->left != nullptr && t->right == nullptr){
//            painter_.drawLine(center, l_center);
//        } else if(t->right != nullptr && t->left == nullptr){
//            painter_.drawLine(center, r_center);
//        } else if(t->right != nullptr && t->left != nullptr){
//            painter_.drawLine(center, l_center);
//            painter_.drawLine(center, r_center);
//        }




}

void Tree_n::paintEvent(QPaintEvent *event) {

    draw(root);


}


