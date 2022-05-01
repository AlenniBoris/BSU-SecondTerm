#ifndef WIDGETS_LABEL_H
#define WIDGETS_LABEL_H

#include <QWidget>
#include <QLabel>

class Label : public QWidget {
Q_OBJECT
public:
    Label(QWidget *parent = 0);
private:
    QLabel *label;
};


#endif //WIDGETS_LABEL_H
