//
// Created by User on 11.05.2022.
//

#include "KeyPress.h"

void KeyPress::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Escape){
        qApp->quit();
    }
}
