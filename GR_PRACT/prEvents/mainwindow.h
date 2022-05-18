#ifndef PREVENTS_MAINWINDOW_H
#define PREVENTS_MAINWINDOW_H

#include <QWidget>
#include "widget.h"
#include <QBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

protected slots:
    void btn_color();
    void line_size();

private:
    Ui::mainwindow *ui;

    QBoxLayout* layout;

    Widget* drawingPanel;
    QSlider* slider;
    QLabel* label;
    QColorDialog *dia;
    QPushButton *btn;

};


#endif //PREVENTS_MAINWINDOW_H
