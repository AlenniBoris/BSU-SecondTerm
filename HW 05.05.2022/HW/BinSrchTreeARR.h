#ifndef HW_BINSRCHTREEARR_H
#define HW_BINSRCHTREEARR_H


#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "BinSrchTree.h"

class BinSrchTreeARR : public BinSrchTree{
protected:
    int size;
    int* array;
public:
    void insertElement(int x);
    void inOrder(int currentIndex);

    void parent(int x);
    int extendSize(int x);

    int* get_arr();


    BinSrchTreeARR (int size) {
        this->size = extendSize(size);
        this->array = new int[this -> size];
        for(int x = 0; x < this -> size; x++){
            array[x] = NULL;
        }
    }

};

#endif //HW_BINSRCHTREEARR_H
