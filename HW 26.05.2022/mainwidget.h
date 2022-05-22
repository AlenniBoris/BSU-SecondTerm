#ifndef HW_26_05_2022_MAINWIDGET_H
#define HW_26_05_2022_MAINWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QLineEdit>
#include <QFileDialog>
#include <vector>
#include "product.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainWidget; }
QT_END_NAMESPACE

class mainWidget : public QWidget {
Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = nullptr);

    ~mainWidget() override;

protected slots:
    void loadLogic();

    void priceSort();
//    void codeSort();
//    void typeSort();

private:
    Ui::mainWidget *ui;

    std::vector<product> products;

    QListWidget* listWidget;
    QPushButton* load_btn;

    QPushButton* priceSort_btn;
//    QPushButton* codeSort_btn;
//    QPushButton* typeSort_btn;



    void printItems();

};


#endif //HW_26_05_2022_MAINWIDGET_H
