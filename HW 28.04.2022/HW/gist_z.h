#ifndef GIST_Z_H
#define GIST_Z_H

#include <QWidget>


class Gist_z : public QWidget
{
 Q_OBJECT
public:
     Gist_z(QWidget *parent = nullptr);
     ~Gist_z(){};
protected:
    void paintEvent(QPaintEvent *event);
private:
    std::vector<int> data;
};

#endif // GIST_Z_H
