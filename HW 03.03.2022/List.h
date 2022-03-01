#ifndef HW_03_03_2022_LIST_H
#define HW_03_03_2022_LIST_H

#include "iostream"
#include "vector"


template<typename T>
struct Node{
    T value_;
    Node* next_;
    Node() = default;
};

template<class T>
class list{
protected:
    Node<T> *head_;
    int size_;
public:
    list() : size_(0){ head_ = nullptr; };

    ~list(){
        Node<T>* Temp_N = head_;
        for (int i = 0; i < size_ - 1; ++i) {
            delete Temp_N->next_;
        }
        delete head_;
    }

    virtual void Push(T data);
    void Print();
    void  Delete(const T& elem);
    T Front();
};

template<typename T>
void list<T>::Push(T data) {
    Node<T>* N_Node = new(Node<T>);
    N_Node->next_ = nullptr;
    N_Node->value_ = data;
    Node<T>* Temp_N = head_;
    if (head_ == nullptr){
        head_ = N_Node;
        ++size_;
        return;
    }
    for (int i = 0; i < size_ - 1; ++i) {
        Temp_N = Temp_N->next_;
    }
    Temp_N->next_ = N_Node;
    ++size_;
}

template<typename T>
void list<T>::Print() {
    Node<T>* Temp_N = head_;
    for (int i = 0; i < size_; i++) {
        std::cout << Temp_N->value_ << ' ' ;
        Temp_N = Temp_N->next_;
    }
}

template<typename T>
void list<T>::Delete(const T &elem) {
    Node<T>* Temp_N = head_;
    Node<T>* Prev_N = nullptr;
    for (int i = 0; i < size_ - 1; i++) {
        if (Temp_N->value_ == elem){
            Prev_N->next_ = Temp_N->next_;
        }
        Prev_N = Temp_N;
        Temp_N = Temp_N->next_;
    }
    --size_;
}

template<typename T>
T list<T>::Front() {
    Node<T>* Temp_N = head_;
    for (int i = 0; i < size_ - 1; i++) {
        Temp_N = Temp_N->next_;
    }
    --size_;
    return Temp_N->value_;
}



#endif //HW_03_03_2022_LIST_H
