#ifndef HW_03_03_2022_SORTED_LIST_H
#define HW_03_03_2022_SORTED_LIST_H

#include "List.h"

template<typename T>
class Sorted_list : public list<T>{
private:
    Node<T> *head_;
    int size_;
public:

    void Push(const T& data);
};
// Написать новый пуш для сортированного списка
template<typename T>
void Sorted_list<T>::Push(const T &data) {
    if (size_ == 0){

    }
}


#endif //HW_03_03_2022_SORTED_LIST_H
