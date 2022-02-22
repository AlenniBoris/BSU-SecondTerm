#ifndef LABA_FUNCTIONS_WITHOUT_CONTEINERS_H
#define LABA_FUNCTIONS_WITHOUT_CONTEINERS_H


#include "fstream"
#include "iomanip"
#include "iostream"
#include "algorithm"
#include "list"
#include "vector"
#include "iterator"


template<typename T>
void Print_List(std::list<T>& Input_List){
    for (std::string Show_Str : Input_List){
        std::cout << Show_Str << ' ';
    }
}

void Fill_List_With_Text(std::ifstream &Input_File, std::list<std::string> &List_For_Input);

void Sort_List(std::list<std::string> &Input_List);

void Show_Sorted_List(std::list<std::string> &Input_List);

void Print_Words_With_Letter(std::list<std::string> &Input_List, char Search_Letter);

void Delete_Words_With_Letter(std::list<std::string> &Input_List, char Search_Letter);




#endif //LABA_FUNCTIONS_WITHOUT_CONTEINERS_H
