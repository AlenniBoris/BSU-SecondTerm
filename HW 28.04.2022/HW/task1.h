#ifndef TASK1_H
#define TASK1_H

#include <QWidget>
#include <fstream>
#include <iostream>

class MyWidget : public QWidget
{
 Q_OBJECT
public:
    MyWidget(QWidget *parent = nullptr){
        std::ifstream file("input.txt");
        std::string str;
        if(file.is_open()){
            std::cout << "open";
        } else{
            std::cout << "can't open";
            abort;
        }
        while(file >> str){
            data.push_back(std::stoi(str));
        }
    };
    ~MyWidget(){};
protected:
    void paintEvent(QPaintEvent *event);
private:
    std::vector<int> data;
};


#endif // TASK1_H
