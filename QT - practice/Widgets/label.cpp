#include "label.h"

#include <QHBoxLayout>
#include <QFont>
#include <QPushButton>

Label::Label(QWidget *parent) : QWidget(parent){
    QString lyrics = "lllssl\nslnfhbvh";
    label = new QLabel(lyrics, this);
    label->setFont(QFont("Purisa", 10));
    QString text_lyr = "ararsrd";
    label = new QLabel(text_lyr, this);
    label->setFont(QFont("Arial", 3));
    QWidget *window = new QWidget;
    QPushButton *button1 = new QPushButton("one");
    QPushButton *button2 = new QPushButton("two");

    label = new QLabel("one", this);

    QHBoxLayout  *vbox = new QHBoxLayout();
    vbox->addWidget(label);
    vbox->addWidget(label);
    vbox->addWidget(button1);
    vbox->addWidget(button2);
    vbox->addWidget(label);
    setLayout(vbox);


}