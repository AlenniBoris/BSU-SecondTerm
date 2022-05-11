#include "BinSrchTreeARR.h"

int BinSrchTreeARR::extendSize(int x) {
    int value = 0;
    for(int y = 0; y < x + 1; y++) {
        value = (2 * value) + 2;
    }
    return value;
}

void BinSrchTreeARR::insertElement(int x) {
    int currentIndex = 0;
    while(true) {
        if(array[currentIndex] == NULL){
            array[currentIndex] = x;
            break;
        }else if(array[currentIndex] <= x) {
            if(array[currentIndex] == x){
                throw std::runtime_error("No equal elements");
            }else
                currentIndex = (2 * currentIndex + 2);
        }else if(array[currentIndex] >= x) {
            if(array[currentIndex] == x){
                throw std::runtime_error("No equal elements");
            }else
                currentIndex = (2 * currentIndex + 1);
        }
    }
}


void BinSrchTreeARR::parent(int x){
    while (x != 0) {
        x = (x-1) / 2;
    }
}

void BinSrchTreeARR::inOrder(int currentIndex){
    if(array[currentIndex] != NULL) {
        inOrder(2 * currentIndex + 1);
        parent(currentIndex);
        std::cout << array[currentIndex] << std::endl;
        inOrder(2 * currentIndex + 2);

    }
}

int* BinSrchTreeARR::get_arr() {
    return array;
}



