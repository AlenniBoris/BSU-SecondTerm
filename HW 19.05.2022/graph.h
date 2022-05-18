#ifndef HW_19_05_2022_GRAPH_H
#define HW_19_05_2022_GRAPH_H

#include <QWidget>
#include <cmath>
#include <QVector>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include "f_x_mean.h"

QT_BEGIN_NAMESPACE
namespace Ui { class graph; }
QT_END_NAMESPACE

class graph : public QWidget {
Q_OBJECT

public:
    explicit graph(QWidget *parent = nullptr);

    ~graph() override;

    static double func_culc(double x);

    void paintEvent(QPaintEvent *event);

private:
    Ui::graph *ui;

    double delta, x;

    QVector<QPointF> pts;
};


#endif //HW_19_05_2022_GRAPH_H
