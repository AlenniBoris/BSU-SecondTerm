#ifndef HW_03_03_2022_LIST_H
#define HW_03_03_2022_LIST_H

#include "iostream"
#include "vector"


template<typename T>
struct Node{
    T value_;
    Node* next_;
    Node(Node* next, T value) : next_(next), value_(value) {};
};

template<typename T>
class list{
protected:
    Node<T> *head_;
    int size_;
public:
    list() : size_(0), head_(nullptr){};


    virtual void Push(const T& data);
    void Print();
    void  Delete(const T& elem);
    T Front();
    void Sort(list<T>& Start_list);

};

template<typename T>
void list<T>::Push(const T& data) {
    if (size_ == 0){
        Node<T>* N_head = new Node<T>(nullptr, data);
        head_ = N_head;
    } else{
        Node<T>* Temp_N = head_;
        for (int i = 0; i < size_ - 1; i++) {
            Temp_N = Temp_N->next_;
        }
        Node<T>* N_Node = new Node<T>(nullptr, data);
        Temp_N->next_ = N_Node;
    }
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

template<typename T>
void list<T>::Sort(list<T> &Start_list) {
    Node<T> *Temp_N = head_;
    list<T> New_l;
    for (int i = 0; i < size_ - 1; ++i) {
        if (Temp_N->value_ >= Temp_N->next_->value_){
            New_l.Push(Temp_N->next_->value_);
            New_l.Push(Temp_N->value_);

        }
        Temp_N = Temp_N->next_;
    }
    Start_list = New_l;
}

//    for (int j = 0; j < For_Sort.size(); ++j) {
//        if (For_Sort[j-1] >= For_Sort[j]){
//            std::swap(For_Sort[j-1],For_Sort[j]);
//        }
//    }
//    for (int k = 0; k < For_Sort.size(); ++k) {
//        std::cout << For_Sort[k] << ' ';
//    }
//

//    Node<T>* Temp_N = head_;
//    for (int i = 0; i < size_-1; i++) {
//        if (Temp_N->value_ >= Temp_N->next_->value_){
//            std::swap(Temp_N->value_,Temp_N->next_->value_);
//        }
//    }
//}


#endif //HW_03_03_2022_LIST_H
