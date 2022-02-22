#include "Functions_With_Conteiners.h"


void Fill_Vector_With_Numbers(std::ifstream &Input_File, std::vector<int> &Vector_For_Input){
    std::copy(std::istream_iterator<int>(Input_File), std::istream_iterator<int>(),
              std::back_inserter(Vector_For_Input));
}

void Print_Vector(std::vector<int> &Vector_For_Input){
    for (int i = 0; i < Vector_For_Input.size(); ++i) {
        std::cout << Vector_For_Input[i] << ' ';
    }
}

void Count_Num_Same(std::vector<int> &Vector_For_Input, int For_Search){
    int Counter = 0;
    for (int i = 0; i < Vector_For_Input.size(); ++i) {
        if(Vector_For_Input[i] = )
    }
}