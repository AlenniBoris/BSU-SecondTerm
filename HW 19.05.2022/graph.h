//
// Created by User on 14.05.2022.
//

#ifndef HW_19_05_2022_GRAPH_H
#define HW_19_05_2022_GRAPH_H

#include <QWidget>
#include <cmath>
#include <QVector>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QRect>

QT_BEGIN_NAMESPACE
namespace Ui { class graph; }
QT_END_NAMESPACE

class graph : public QWidget {
Q_OBJECT

public:
    explicit graph(QWidget *parent = nullptr);

    ~graph() override;

protected:
    void paintEvent(QPaintEvent *event);
    double func_culc(int x);

private:
    Ui::graph *ui;

    double delta, x;
    QVector<QPointF> pts;


};


#endif //HW_19_05_2022_GRAPH_H
