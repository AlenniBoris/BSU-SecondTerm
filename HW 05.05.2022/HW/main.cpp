#include <iostream>
#include <QApplication>
#include "tree_node.h"
#include "tree_arr.h"
#include "BinSrchTreeARR.h"
#include "N_MY_ARRTR.h"



using namespace std;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    BinSrchTree tree;
    tree.insert(15);
    tree.insert(19);
    tree.insert(2);
    tree.insert(5);
    tree.insert(7);
    tree.insert(18);
    tree.insert(-2);
    tree.insert(43);
    tree.insert(17);
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

    Widget w;
    w.show();

    return a.exec();
}