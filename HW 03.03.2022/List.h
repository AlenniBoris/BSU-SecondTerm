#ifndef HW_03_03_2022_LIST_H
#define HW_03_03_2022_LIST_H

#include "iostream"
#include "vector"


template<typename T>
struct Node{
    T value_;
    Node* next_;
    Node(Node* next, T data) : next_(next), value_(data) {};
};

template<class T>
class list{
protected:
    Node<T> *head_;
    int size_;
public:
    class iterator: public std::iterator<std::forward_iterator_tag, T>{
    public:
        Node<T>* node_;
        iterator(Node<T>* node = nullptr) : node_(node) {};
        bool operator==(const iterator& node)
        {
            return node_ == node.node_;
        }
        bool operator!=(const iterator& node)
        {
            return node != *this;
        }
        iterator& operator=(const iterator& node) {
            if (this != node)
                node_ = node.node_;
            return *this;
        }
        const iterator& operator++() {
            node_ = node_->next;
            return *this;
        }
    };

    list() : size_(0){ head_ = nullptr; };

    ~list(){
        Node<T>* Temp_N = head_;
        for (int i = 0; i < size_ - 1; ++i) {
            delete Temp_N->next_;
        }
        delete head_;
    }

    void Push(T& data);
    void Print();
    void  Delete(const T& elem);
    T Front();
};

template<typename T>
void list<T>::Push(T& data) {
    if (size_ == 0){
        Node<T>* N_Node = new Node<T>(nullptr, data);
        head_ = N_Node;
    }else{
        Node<T>* T_Node = head_;
        for (int i = 0; i < size_ - 1; ++i) {
            T_Node = T_Node->next_;
        }
        Node<T>* N_Node = new Node<T>(nullptr, data);
        T_Node->next_ = N_Node;
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



#endif //HW_03_03_2022_LIST_H
