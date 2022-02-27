#ifndef HW_03_03_2022_STACK_H
#define HW_03_03_2022_STACK_H

#include "List.h"

template<typename T>
class Stack{
private:
    list<T> stack_;
    int size_;
public:
    Stack() : stack_(), size_(0) {};

    void Push(T data);
    void Pop();
    T Top();
    void Print();

};

template<typename T>
void Stack<T>::Push(T data) {
    stack_.Push(data);
    ++size_;
}

template<typename T>
void Stack<T>::Pop() {
    stack_.Front();
}

template<typename T>
T Stack<T>::Top() {
    --size_;
    return stack_.Front();
}

template<typename T>
void Stack<T>::Print() {
    int size = size_;
    for (int i = 0; i < size; ++i) {
        std::cout << this->Top() << ' ';
    }
}



#endif //HW_03_03_2022_STACK_H
