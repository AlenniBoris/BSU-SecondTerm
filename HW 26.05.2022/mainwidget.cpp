#include "mainwidget.h"
#include "ui_mainWidget.h"


mainWidget::mainWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainWidget) {
    ui->setupUi(this);

    QBoxLayout* layout = new QVBoxLayout(this);

    listWidget = new QListWidget(this);

    load_btn = new QPushButton("Load items",this);
    connect(load_btn, SIGNAL(clicked()), SLOT(loadLogic()));

    priceSort_btn = new QPushButton("Sort by price",this);
    connect(priceSort_btn, SIGNAL(clicked()), SLOT(priceSort()));

//    codeSort_btn = new QPushButton("Sort by code",this);
//    connect(codeSort_btn, SIGNAL(clicked()), SLOT(codeSort()));
//
//    typeSort_btn = new QPushButton("Sort by type",this);
//    connect(typeSort_btn, SIGNAL(clicked()), SLOT(typeSort()));

    layout->addWidget(listWidget);
    layout->addWidget(load_btn);
    layout->addWidget(priceSort_btn);
//    layout->addWidget(codeSort_btn);
//    layout->addWidget(typeSort_btn);
}

mainWidget::~mainWidget() {
    delete ui;
}

void mainWidget::loadLogic() {
    QString str = QFileDialog::getOpenFileName(0,"Choose File", "","*.txt");
    getFileInfo(products, str.toStdString());
    printItems();
}

void mainWidget::printItems() {
    listWidget->clear();
    for (auto product : products) {
        QString str(product.showInString().c_str());
        listWidget->addItem(str);
    }
}

void mainWidget::priceSort() {
    listWidget->clear();
    for (int i = 0; i < products.size(); ++i) {
        while(products[i].getPrice() > products[i+1].getPrice()){
            std::swap(products[i],products[i+1]);
            i = 0;
        }
    }
    printItems();
}

