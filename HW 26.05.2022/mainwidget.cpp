#include "mainwidget.h"
#include "ui_mainWidget.h"
#include "addDialog.h"

mainWidget::mainWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainWidget) {
    ui->setupUi(this);

    QBoxLayout* layout = new QVBoxLayout(this);

    listWidget = new QListWidget(this);

    widgetMenu = new QMenuBar(this);

    // fileMenu - begin
    fileMenu = new QMenu("File acts");

    loadAct = new QAction("load file", this);
    connect(loadAct, SIGNAL(triggered()), SLOT(loadLogic()));
    loadAct->setShortcut(tr("CTRL+L"));

    addNewAct = new QAction("Add new item", this);
    connect(addNewAct, SIGNAL(triggered()), SLOT(addNew()));
    addNewAct->setShortcut(tr("CTRL+N"));

    deleteAct = new QAction("Delete item", this);
    connect(deleteAct, SIGNAL(triggered()), SLOT(deleteItem()));
    deleteAct->setShortcut(tr("Delete"));


    fileMenu->addAction(loadAct);
    fileMenu->addAction(addNewAct);
    fileMenu->addAction(deleteAct);
    // fileMenu - end

    // sortMenu - begin
    sortMenu = new QMenu("Sort acts");

    priceSortAct = new QAction("Sort by price", this);
    connect(priceSortAct, SIGNAL(triggered()), SLOT(priceSort()));
    sortMenu->addAction(priceSortAct);

    codeSortAct = new QAction("Sort by code", this);
    connect(codeSortAct, SIGNAL(triggered()), SLOT(codeSort()));
    sortMenu->addAction(codeSortAct);

    typeSortAct = new QAction("Sort by type", this);
    connect(typeSortAct, SIGNAL(triggered()), SLOT(typeSort()));
    sortMenu->addAction(typeSortAct);
    // sortMenu - end

    // search - begin
    srchMenu = new QMenu("Search acts");

    srchProdAct = new QAction("Find elements",this);
    connect(srchProdAct, SIGNAL(triggered()), SLOT(srchLogic()));
    srchProdAct->setShortcut(tr("CTRL+F+P"));
    srchMenu->addAction(srchProdAct);

    srchLessAct = new QAction("Find less than", this);
    connect(srchLessAct, SIGNAL(triggered()), SLOT(srchLessLogic()));
    srchLessAct->setShortcut(tr("CTRL+F+L"));
    srchMenu->addAction(srchLessAct);

    nameLbl = new QLabel("Enter name: ");
    nameEdit = new QLineEdit(this);
    typeLbl = new QLabel("Enter type: ");
    typeEdit = new QLineEdit(this);

    lessLbl = new QLabel("Enter minimum number: ");
    lessEdit = new QLineEdit(this);

    srchWidget = new searchedWidget();
    lessWidget = new searchedWidget();
    // search - end

    //Menu+layout setup
    widgetMenu->addMenu(fileMenu);
    widgetMenu->addMenu(sortMenu);
    widgetMenu->addMenu(srchMenu);

    layout->addWidget(widgetMenu);
    layout->addWidget(listWidget);
    layout->addWidget(nameLbl);
    layout->addWidget(nameEdit);
    layout->addWidget(typeLbl);
    layout->addWidget(typeEdit);
    layout->addWidget(lessLbl);
    layout->addWidget(lessEdit);
//Menu+layout setup

    setLayout(layout);
}

mainWidget::~mainWidget() {
    delete ui;
}

void mainWidget::loadLogic() {
    QString str = QFileDialog::getOpenFileName(0,"Choose File", "","*.txt");
    getFileInfo(products, str.toStdString());
    typeEdit->clear();
    nameEdit->clear();
    lessEdit->clear();
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
    for (int i = 0; i < products.size() - 1; ++i) {
        if(products[i].getPrice() > products[i+1].getPrice()){
            std::swap(products[i],products[i+1]);
            i = 0;
        }
    }
    printItems();
}

void mainWidget::codeSort() {
    listWidget->clear();
    for (int i = 0; i < products.size() - 1; ++i) {
        if(products[i].getCode() > products[i+1].getCode()){
            std::swap(products[i],products[i+1]);
            i = 0;
        }
    }
    printItems();
}

void mainWidget::typeSort() {
    listWidget->clear();
    for (int i = 0; i < products.size() - 1; ++i) {
        if(products[i].getType() > products[i+1].getType()){
            std::swap(products[i],products[i+1]);
            i = 0;
        }
    }
    printItems();
}

void mainWidget::srchLogic() {
    int count = 0;
    for (auto product : products) {
        if (product.getType().contains(typeEdit->text()) && product.getName().contains(nameEdit->text())) {
            srchWidget->addFinded(QString::fromStdString(product.showInString()));
            count++;
        }
        else if(!product.getType().contains(typeEdit->text()) || !product.getName().contains(nameEdit->text())){
            continue;
        }
    }
    if (count == 0){
        srchWidget->addFinded(QString::fromStdString("Not Found"));
    }
    srchWidget->show();
}

void mainWidget::srchLessLogic() {
    int count = 0;
    for (auto product : products) {
        if (product.getNum() < lessEdit->text().toInt()){
            lessWidget->addFinded(QString::fromStdString(product.showInString()));
            count++;
        } else{
            continue;
        }
    }
    if (count == 0){
        lessWidget->addFinded(QString::fromStdString("Not Found"));
    }
    lessWidget->show();
}

void mainWidget::addNew() {
    addDialog *addDia = new addDialog(this);
    if(addDia->exec() == QDialog::Accepted){
        Product tmp = addDia->product();
        products.push_back(tmp);
        printItems();
    }
}

void mainWidget::deleteItem() {
    int num = listWidget->currentRow();
    if (num != -1){
        listWidget->takeItem(num);

        auto iter = products.begin();
        for (int i = 0; i != num; ++i) {
            iter++;
        }
        products.erase(iter);
    }
}


