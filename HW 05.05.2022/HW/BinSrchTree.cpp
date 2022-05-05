#include "BinSrchTree.h"

Node *BinSrchTree::insert(int x, Node *t) {
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

void BinSrchTree::true_order(Node *t) {
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

Node* BinSrchTree::ret_node() {
    return root;
}

