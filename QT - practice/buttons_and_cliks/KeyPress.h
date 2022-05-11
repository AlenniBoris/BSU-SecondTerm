//
// Created by User on 11.05.2022.
//

#ifndef BUTTONS_AND_CLIKS_KEYPRESS_H
#define BUTTONS_AND_CLIKS_KEYPRESS_H

#include <QWidget>
#include <QKeyEvent>
#include <QApplication>

class KeyPress : public QWidget{

public:
    KeyPress(QWidget *parent = 0){};

protected:
    void keyPressEvent(QKeyEvent *e);

};


#endif //BUTTONS_AND_CLIKS_KEYPRESS_H
