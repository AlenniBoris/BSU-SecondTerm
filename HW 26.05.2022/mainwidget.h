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
private:
    Ui::mainWidget *ui;

    std::list<product> products;

    QListWidget* listWidget;
    QPushButton* load_btn;


    void printItems();

};


#endif //HW_26_05_2022_MAINWIDGET_H
