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



#include <QMenu>
#include <QMenuBar>

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
//
    void priceSort();
    void codeSort();
    void typeSort();

    void srchLogic();
    void srchLessLogic();


//    void clrBtnLogic();
private:
    Ui::mainWidget *ui;

    std::vector<product> products;

    QListWidget* listWidget;

    QMenuBar* widgetMenu;

    QMenu* fileMenu;
    QAction* loadAct;

    QMenu* sortMenu;
    QAction* priceSortAct;
    QAction* codeSortAct;
    QAction* typeSortAct;


    QMenu* srchMenu;
    QAction* srchProdAct;
    QAction* srchLessAct;
    QLabel* typeLbl;
    QLineEdit* typeEdit;
    QLabel* nameLbl;
    QLineEdit* nameEdit;
    QLabel* lessLbl;
    QLineEdit* lessEdit;

    void printItems();

};


#endif //HW_26_05_2022_MAINWIDGET_H
