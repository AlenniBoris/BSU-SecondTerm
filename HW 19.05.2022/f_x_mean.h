#ifndef HW_19_05_2022_F_X_MEAN_H
#define HW_19_05_2022_F_X_MEAN_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class f_x_mean; }
QT_END_NAMESPACE

class f_x_mean : public QWidget{
Q_OBJECT

public:

    explicit f_x_mean(QWidget *parent = nullptr);

    ~f_x_mean() override;

protected slots:
    void clear_f();
    void set_f();

private:
    Ui::f_x_mean *ui;

    QLineEdit* editX;
    QLineEdit* editY;
    QPushButton* f_btn;
};


#endif //HW_19_05_2022_F_X_MEAN_H
