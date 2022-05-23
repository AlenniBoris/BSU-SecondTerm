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

    codeSort_btn = new QPushButton("Sort by code",this);
    connect(codeSort_btn, SIGNAL(clicked()), SLOT(codeSort()));

    typeSort_btn = new QPushButton("Sort by type",this);
    connect(typeSort_btn, SIGNAL(clicked()), SLOT(typeSort()));

    srchName_lbl = new QLabel("Enter name of product",this);
    srchName = new QLineEdit(this);

    srchType_lbl = new QLabel("Enter type of product",this);
    srchType = new QLineEdit(this);

    srch_btn = new QPushButton("Search", this);
    connect(srch_btn, SIGNAL(clicked()), SLOT(srchBtnLogic()));

    layout->addWidget(listWidget);
    layout->addWidget(load_btn);
    layout->addWidget(priceSort_btn);
    layout->addWidget(codeSort_btn);
    layout->addWidget(typeSort_btn);

    layout->addWidget(srchName_lbl);
    layout->addWidget(srchName);

    layout->addWidget(srchType_lbl);
    layout->addWidget(srchType);
    layout->addWidget(srch_btn);
}

mainWidget::~mainWidget() {
    delete ui;
}

void mainWidget::loadLogic() {
    QString str = QFileDialog::getOpenFileName(0,"Choose File", "","*.txt");
    getFileInfo(products, str.toStdString());
    printItems(products);
}

void mainWidget::printItems(std::vector<product>& itemList) {
    listWidget->clear();
    for (auto product : itemList) {
        QString str(product.showInString().c_str());
        listWidget->addItem(str);
    }
}

void mainWidget::priceSort() {
    listWidget->clear();
    for (int i = 0; i < products.size() - 1; ++i) {
        if(products[i].getPrice() > products[i+1].getPrice()){
            std::swap(products[i],products[i+1]);
            i = 0;
        }
    }
    printItems(products);
}

void mainWidget::codeSort() {
    listWidget->clear();
    for (int i = 0; i < products.size() - 1; ++i) {
        if(products[i].getCode() > products[i+1].getCode()){
            std::swap(products[i],products[i+1]);
            i = 0;
        }
    }
    printItems(products);
}

void mainWidget::typeSort() {
    listWidget->clear();
    for (int i = 0; i < products.size() - 1; ++i) {
        if(products[i].getType() > products[i+1].getType()){
            std::swap(products[i],products[i+1]);
            i = 0;
        }
    }
    printItems(products);
}

void mainWidget::srchBtnLogic() {
    listWidget->clear();
    QString qName = srchName->text();
    QString qType = srchType->text();
    for (int i = 0; i < products.size() - 1; ++i) {
        if(products[i].getName() == qName.toStdString() && products[i].getType() == qType.toStdString()){
            srchVect.push_back(products[i]);
        }
    }
    printItems(srchVect);
}

