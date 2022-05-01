#ifndef CROSS_ZERO_H
#define CROSS_ZERO_H

#include <QWidget>
#include <QPainter>
#include <vector>

class Cross_zero : public QWidget
{
 Q_OBJECT
public:
    Cross_zero(QWidget *parent = nullptr){
        data = {
                {1,0,1,1},
                {0,1,0,0},
                {-1,-1,1,0},
                {1,1,0,0}
                  };
    };
    ~Cross_zero(){};
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    std::vector<std::vector<int>> data;
};

QString draw_el(int num_);

#endif // CROSS_ZERO_H
