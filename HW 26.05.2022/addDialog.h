//
// Created by User on 24.05.2022.
//

#ifndef HW_26_05_2022_ADDDIALOG_H
#define HW_26_05_2022_ADDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class Product;

class addDialog : public QDialog{
public:
    addDialog(QWidget *parent = nullptr);
    Product product() const;

private:
    QLineEdit* nameEdit;
    QLineEdit* typeEdit;
    QLineEdit* codeEdit;
    QLineEdit* priceEdit;
    QLineEdit* numEdit;
};


#endif //HW_26_05_2022_ADDDIALOG_H
