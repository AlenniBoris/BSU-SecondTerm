//
// Created by User on 15.05.2022.
//

#ifndef HW_19_05_2022_MAINWINDOW_H
#define HW_19_05_2022_MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "graph.h"
#include "f_x_mean.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    Ui::mainwindow *ui;

    graph* f_graph;
    QPushButton* dialog_fx_btn;

    f_x_mean* f_wind;

protected slots:
    void f_btn_logic();
};


#endif //HW_19_05_2022_MAINWINDOW_H
