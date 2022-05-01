#include <iostream>
#include <QApplication>
#include "BinSrchTree.h"
#include "BinSrchTreeARR.h"
#include "tree_node.h"

using namespace std;

int main(int argc, char *argv[]) {
    BinSrchTree tree;
    tree.insert(20);
    tree.insert(19);
    tree.insert(142);
    tree.insert(95);
    tree.insert(154);
    tree.insert(15);
    tree.insert(1);
    tree.insert(-32);
    tree.insert(18);

    tree.print();

    cout << '\n' << tree.min_num_() << ' ' << tree.max_num_();
    BinSrchTreeARR frank(5);
    frank.insertElement(4);
    frank.insertElement(6);
    frank.insertElement(9);
    frank.insertElement(3);
    frank.insertElement(2);
    frank.inOrder(0);

//    QApplication a(argc, argv);
//    Tree_n t_n;
//    t_n.show();

    return 0;
}



