#ifndef LABA_FUNCTIONS_WITH_CONTEINERS_H
#define LABA_FUNCTIONS_WITH_CONTEINERS_H


#include "fstream"
#include "iostream"
#include "algorithm"
#include "vector"
#include "iterator"
#include "numeric"
#include "list"

void Fill_Vector_With_Numbers(std::ifstream &Input_File, std::vector<int> &Vector_For_Input);

void Print_Vector(std::vector<int> &Vector_For_Input);

int Count_Num_Same(std::vector<int> &Vector_For_Input, int For_Search);

int CountIF_Num_Same(std::vector<int> &Vector_For_Input, int For_Search);

int Find_Average(std::vector<int> &Vector_For_Input);

int Count_Equal_Strings(std::list<std::string> &List_For_Input, std::string For_Search);

int CountIF_Equal_Strings(std::list<std::string> &List_For_Input, std::string For_Search);


#endif //LABA_FUNCTIONS_WITH_CONTEINERS_H
