#include <QApplication>
#include "mainwidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    mainWidget widget;
    widget.resize(800,800);
    widget.show();

    return a.exec();
}
