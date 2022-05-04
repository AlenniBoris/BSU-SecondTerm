#ifndef HW_BINSRCHTREE_H
#define HW_BINSRCHTREE_H

#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;
};

class BinSrchTree {
protected:

    Node* root = nullptr;
    Node* insert(int x, Node* t);
    void true_order(Node* t);
    Node* find_min(Node* t);
    Node* find_max(Node* t);
public:
    BinSrchTree(){
        root = nullptr;
    }
    void insert(int num_);
//    void show_leaf(int num_);
    void print();
    int min_num_();
    int max_num_();
    Node* ret_node();
};



#endif //HW_BINSRCHTREE_H
