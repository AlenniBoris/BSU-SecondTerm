#include "task1.h"
#include "gist_z.h"
#include "cross_zero.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MyWidget w;
//    w.show();


//    Gist_z g;
//    g.show();

    Cross_zero cz;
    cz.show();
    cz.setFixedSize(600,600);

    return a.exec();
}
