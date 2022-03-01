#ifndef HW_03_03_2022_SORTED_LIST_H
#define HW_03_03_2022_SORTED_LIST_H

#include "List.h"

template<class T>
class Sorted_list : public list<T>{
public:
    void Push(T data){
        Node<T>* N_Node = new(Node<T>);
        N_Node->next_ = nullptr;
        N_Node->value_ = data;
        if (list<T>::head_ == nullptr){
            list<T>::head_ = N_Node;
            ++list<T>::size_;
            return;
        }

        Node<T>* F_temp = list<T>::head_;
        Node<T>* S_temp = list<T>::head_;

        for (int i = 0; i < list<T>::size_; ++i) {
            if (F_temp->value_ < data){
                if (F_temp->next_ == nullptr){
                    ++list<T>::size_;
                    F_temp->next_ = N_Node;
                    return;
                }
                S_temp = F_temp;
                F_temp = F_temp->next_;
            }
            else{
                if (F_temp == list<T>::head_){
                    N_Node->next_ = list<T>::head_;
                    list<T>::head_ = N_Node;
                    ++list<T>::size_;
                    return;
                }
                S_temp->next_ = N_Node;
                N_Node->next_ = F_temp;
                ++list<T>::size_;
                return;
            }
        }
    }
};

#endif //HW_03_03_2022_SORTED_LIST_H
