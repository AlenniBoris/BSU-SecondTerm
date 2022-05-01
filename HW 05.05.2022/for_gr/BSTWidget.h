#ifndef FOR_GR_BSTWIDGET_H
#define FOR_GR_BSTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>

class BSTWidget : public QWidget
{
Q_OBJECT
public:
    BSTWidget(QWidget *parent = nullptr);
    ~BSTWidget(){};
protected:
    void paintEvent(QPaintEvent *event);
private:
    int height;
    int width;
};

#endif //FOR_GR_BSTWIDGET_H
