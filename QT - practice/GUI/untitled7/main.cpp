#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>

class cursors : public QWidget {
    public : cursors(QWidget *parent = 0);
};

cursors::cursors(QWidget *parent) : QWidget(parent){
    QFrame *frame1 = new QFrame(this);
    frame1->setFrameStyle(QFrame::Box);
    frame1->setCursor(Qt::BusyCursor);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(frame1, 0, 0);

    setLayout(grid);
}


class button : public QWidget{
    public : button(QWidget *parent = 0);
};

button::button(QWidget *parent):QWidget(parent){
    QPushButton *quitbtn = new QPushButton("Quit", this);
    quitbtn->setGeometry(100,150,75,30);

    connect(quitbtn, &QPushButton::clicked, qApp, &QApplication::quit);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    button window;

    window.resize(400, 400);
    window.setWindowTitle("Simple example");

    window.show();

    return app.exec();
}
