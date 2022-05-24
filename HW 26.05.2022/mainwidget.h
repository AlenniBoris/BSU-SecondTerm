#ifndef HW_26_05_2022_MAINWIDGET_H
#define HW_26_05_2022_MAINWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>
#include <vector>
#include <QString>
#include <QMenu>
#include <QMenuBar>
#include "product.h"
#include "searchedwidget.h"



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
    void addNew();
    void deleteItem();

    void priceSort();
    void codeSort();
    void typeSort();

    void srchLogic();
    void srchLessLogic();

private:
    Ui::mainWidget *ui;

    std::vector<Product> products;

    QListWidget* listWidget;

    QMenuBar* widgetMenu;

    QMenu* fileMenu;
    QAction* loadAct;
    QAction* addNewAct;
    QAction* deleteAct;

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

    searchedWidget* srchWidget;
    searchedWidget* lessWidget;

    void printItems();
};


#endif //HW_26_05_2022_MAINWIDGET_H
