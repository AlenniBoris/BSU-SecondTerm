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
    void true_order(Node* t); //обход

public:
    Node* ret_node();
    BinSrchTree(){
        root = nullptr;
    }
    void insert(int num_);
    void print();

};



#endif //HW_BINSRCHTREE_H
