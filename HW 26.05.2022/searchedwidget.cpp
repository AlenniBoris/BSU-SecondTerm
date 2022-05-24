#include "searchedwidget.h"
#include "ui_searchedWidget.h"

searchedWidget::searchedWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::searchedWidget) {
    ui->setupUi(this);

    QBoxLayout* srchListLayout = new QVBoxLayout(this);
    searchedList = new QListWidget(this);
    srchListLayout->addWidget(searchedList);

    setLayout(srchListLayout);
}

searchedWidget::~searchedWidget() {
    delete ui;
}

void searchedWidget::addFinded(const QString& qString){
    searchedList->addItem(qString);
}

