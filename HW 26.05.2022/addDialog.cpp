#include "addDialog.h"
#include "product.h"

addDialog::addDialog(QWidget *parent) {
    nameEdit = new QLineEdit;
    typeEdit = new QLineEdit;
    codeEdit = new QLineEdit;
    priceEdit = new QLineEdit;
    numEdit = new QLineEdit;

    QLabel *nameLbl= new QLabel("Name");
    QLabel *typeLbl= new QLabel("Type");
    QLabel *codeLbl= new QLabel("Code");
    QLabel *priceLbl= new QLabel("Price");
    QLabel *numLbl= new QLabel("Number");

    QPushButton *okButton = new QPushButton("Ok");
    QPushButton *cancelButton = new QPushButton("Cancel");

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(nameLbl, 0, 0);
    layout->addWidget(typeLbl, 1, 0);
    layout->addWidget(codeLbl, 2, 0);
    layout->addWidget(priceLbl, 3, 0);
    layout->addWidget(numLbl, 4, 0);

    layout->addWidget(nameEdit, 0, 1);
    layout->addWidget(typeEdit, 1, 1);
    layout->addWidget(codeEdit, 2, 1);
    layout->addWidget(priceEdit, 3, 1);
    layout->addWidget(numEdit, 4, 1);

    layout->addWidget(okButton, 5, 0);
    connect(okButton, SIGNAL(clicked()), SLOT(accept()));
    layout->addWidget(cancelButton, 5, 1);
    connect(cancelButton, SIGNAL(clicked()), SLOT(reject()));

    setLayout(layout);
}

Product addDialog::product() const {
    QString name = nameEdit->text();
    QString type = typeEdit->text();
    unsigned int code = codeEdit->text().toInt();
    unsigned int price = priceEdit->text().toInt();
    unsigned int num = numEdit->text().toInt();
    return {name, type, code, price, num};
}

