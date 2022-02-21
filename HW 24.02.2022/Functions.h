#ifndef HW_24_02_2022_FUNCTIONS_H
#define HW_24_02_2022_FUNCTIONS_H

#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <iterator>

template<typename T>
void Show_Vector(const std::vector<T>& Vector){
    for (T Show_Inf : Vector)
        std::cout << Show_Inf << " ";
}
template<typename T>
void To_New_Container(std::list<T>&list, std::vector<T>& vector){
    std::copy(list.begin(), list.end(), std::inserter(vector,vector.begin()));
}



void Fill_List_With_Text(std::ifstream &Input_File, std::list<std::string> &List_For_Input);
void Show_List(std::list<std::string> &List_For_Input);

//Task 4

std::list<std::string> Find_By_Letter_Func(std::list<std::string> &For_Search, char Search_Letter);
std::list<std::string> Find_By_Letter_Lambda(std::list<std::string> &For_Search, char Search_Letter);

void Delete_With_Letter(std::list<std::string> &For_Search, char Search_Letter);
int Count_With_Letter(std::list<std::string> &For_Search, char Search_Letter);
void Show_Reverse(std::list<std::string> &List_For_Input);
void Print_Unique_Alphabet(std::ifstream &Input_File);
void Count_Double(std::ifstream &Input_File);









#endif //HW_24_02_2022_FUNCTIONS_H
