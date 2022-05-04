#include "BinSrchTree.h"

BinSrchTree::Node *BinSrchTree::insert(int x, BinSrchTree::Node *t) {
    if(t == nullptr){
        t = new Node;
        t->data = x;
        t->left = nullptr;
        t->right = nullptr;
    }
    else if(t->data < x)
        t->right = insert(x, t->right);
    else if (t->data > x)
        t->left = insert(x, t->left);
    return t;
}

void BinSrchTree::true_order(BinSrchTree::Node *t) {
    if (t == nullptr)
        return;
    true_order(t->left);
    std::cout << t->data << ' ';
    true_order(t->right);
}

void BinSrchTree::print() {
    true_order(root);
    std::cout << std::endl;
}

void BinSrchTree::insert(int num_) {
    root = insert(num_, root);
}

BinSrchTree::Node *BinSrchTree::find_min(BinSrchTree::Node *t) {
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return find_min(t->left);
}

int BinSrchTree::min_num_() {
    return find_min(root)->data;
}

int BinSrchTree::max_num_() {
    return find_max(root)->data;
}

BinSrchTree::Node *BinSrchTree::find_max(BinSrchTree::Node *t) {
    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return find_max(t->right);
}