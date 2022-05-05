#include <iostream>
#include <QApplication>
//#include "BinSrchTree.h"
//#include "BinSrchTreeARR.h"
#include "tree_node.h"
#include "tree_arr.h"


using namespace std;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    BinSrchTree tree;
    tree.insert(15);
    tree.insert(19);
    tree.insert(2);
    tree.insert(5);
    tree.insert(7);
    tree.insert(15);
    tree.insert(18);
    tree.insert(-2);
    tree.insert(43);
    tree.insert(17);
    tree.insert(689);
    tree.insert(-137);
    tree.insert(376);
    tree.insert(0);

    tree.print();


    cout << endl;


    BinSrchTreeARR frank(5);
    frank.insertElement(4);
    frank.insertElement(6);
    frank.insertElement(9);
    frank.insertElement(3);
    frank.insertElement(2);
    frank.inOrder(0);



    tree_node tr(tree);
    tr.show();
    tr.resize(1000,1000);


//    tree_arr tr(frank);
//    tr.show();
//    tr.resize(1000,1000);

    return a.exec();
}