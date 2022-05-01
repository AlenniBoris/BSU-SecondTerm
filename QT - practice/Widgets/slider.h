#ifndef WIDGETS_SLIDER_H
#define WIDGETS_SLIDER_H

#include <QWidget>
#include <QSlider>
#include <QLabel>

class Slider : public QWidget {
Q_OBJECT

public:
    Slider(QWidget *parent = 0);

private:
    QSlider *slider;
    QLabel *label;
};


#endif //WIDGETS_SLIDER_H
