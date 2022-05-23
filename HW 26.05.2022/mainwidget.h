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
#include <QLineEdit>
#include <vector>
#include <QTextEdit>
#include <QString>
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
    void codeSort();
    void typeSort();

    void srchBtnLogic();

private:
    Ui::mainWidget *ui;

    std::vector<product> products;
    std::vector<product> srchVect;

    QListWidget* listWidget;
    QPushButton* load_btn;

    QPushButton* priceSort_btn;
    QPushButton* codeSort_btn;
    QPushButton* typeSort_btn;

    QLabel* srchName_lbl;
    QLineEdit* srchName;

    QLabel* srchType_lbl;
    QLineEdit* srchType;

    QPushButton* srch_btn;

    void printItems(std::vector<product>&);

};


#endif //HW_26_05_2022_MAINWIDGET_H
