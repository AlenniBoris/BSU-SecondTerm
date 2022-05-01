#include "mainwindow.h"

#include <QApplication>
#include "lines.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    lines window;
    window.resize(400,400);
    window.show();

    return a.exec();
}
