#ifndef UNTITLED1_BINSRCHTREEARR_H
#define UNTITLED1_BINSRCHTREEARR_H

#include <cstddef>
#include <stdexcept>
#include <iostream>

class BinSrchTreeARR{
public:
    int size;
    int* array;

    void insertElement(int x);
    void inOrder(int currentIndex);

    void parent(int x);
    int extendSize(int x);

    BinSrchTreeARR (int size) {
        this->size = extendSize(size);
        this->array = new int[this -> size];
        for(int x = 0; x < this -> size; x++){
            array[x] = NULL;
        }
    }
};



#endif //UNTITLED1_BINSRCHTREEARR_H
