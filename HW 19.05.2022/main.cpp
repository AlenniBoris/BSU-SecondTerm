#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

//    graph button;
//    button.resize(800,800);
//    button.show();

//    f_x_mean mean;
//    mean.show();

    mainwindow w;
    w.resize(800,800);
    w.show();

    return a.exec();
}
