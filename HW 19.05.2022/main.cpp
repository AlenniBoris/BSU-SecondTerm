#include <QApplication>
#include <QPushButton>
#include "graph.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    graph button;
    button.resize(500,500);
    button.show();

    return a.exec();
}
