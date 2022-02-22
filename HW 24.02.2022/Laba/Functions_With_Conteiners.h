#ifndef LABA_FUNCTIONS_WITH_CONTEINERS_H
#define LABA_FUNCTIONS_WITH_CONTEINERS_H


#include "fstream"
#include "iomanip"
#include "iostream"
#include "algorithm"
#include "vector"
#include "iterator"




void Fill_Vector_With_Numbers(std::ifstream &Input_File, std::vector<int> &Vector_For_Input);

void Print_Vector(std::vector<int> &Vector_For_Input);

void Count_Num_Same(std::vector<int> &Vector_For_Input, int For_Search);

#endif //LABA_FUNCTIONS_WITH_CONTEINERS_H
