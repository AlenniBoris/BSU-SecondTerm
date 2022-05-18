#include "f_x_mean.h"
#include "ui_f_x_mean.h"



f_x_mean::f_x_mean(QWidget *parent) :
        QWidget(parent), ui(new Ui::f_x_mean) {
    ui->setupUi(this);

    QBoxLayout* layout = new QHBoxLayout;

    QLabel* labelX = new QLabel("x",  this);
    labelX->setFixedSize(40,30);
    QLabel* labelY = new QLabel("f(x)",  this);
    labelY->setFixedSize(40,30);

    editX = new QLineEdit(this);
    connect(editX, SIGNAL(textChanged(const QString &)), SLOT(clear_f()));

    editY = new QLineEdit(this);
    editY->setDisabled(true);


    f_btn = new QPushButton("f(x)", this);
    connect(f_btn, SIGNAL(clicked()), SLOT(set_f()));

    layout->addWidget(labelX);
    layout->addWidget(editX);
    layout->addWidget(f_btn);
    layout->addWidget(labelY);
    layout->addWidget(editY);


    setLayout(layout);

}

f_x_mean::~f_x_mean() {
    delete ui;
}

void f_x_mean::clear_f() {
    editY->clear();
}

void f_x_mean::set_f() {
    QString temp_str = editX->text();
    editY->setText(QString::number(-1*graph::func_culc(temp_str.toDouble())));
}



