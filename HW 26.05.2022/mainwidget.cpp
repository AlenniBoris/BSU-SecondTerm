#include "mainwidget.h"
#include "ui_mainWidget.h"


mainWidget::mainWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainWidget) {
    ui->setupUi(this);

    QBoxLayout* layout = new QVBoxLayout(this);

    listWidget = new QListWidget(this);

    load_btn = new QPushButton("Load items",this);
    connect(load_btn, SIGNAL(clicked()), SLOT(loadLogic()));

    layout->addWidget(listWidget);
    layout->addWidget(load_btn);
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

