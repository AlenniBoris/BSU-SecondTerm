#include "Functions_With_Conteiners.h"


void Fill_Vector_With_Numbers(std::ifstream &Input_File, std::vector<int> &Vector_For_Input) {
    std::copy(std::istream_iterator<int>(Input_File), std::istream_iterator<int>(),
              std::back_inserter(Vector_For_Input));
}

void Print_Vector(std::vector<int> &Vector_For_Input) {
    for (int i = 0; i < Vector_For_Input.size(); ++i) {
        std::cout << Vector_For_Input[i] << ' ';
    }
}

int Count_Num_Same(std::vector<int> &Vector_For_Input, int For_Search) {
    return std::count(Vector_For_Input.begin(), Vector_For_Input.end(), For_Search);
}

int CountIF_Num_Same(std::vector<int> &Vector_For_Input, int For_Search) {
    return std::count_if(Vector_For_Input.begin(), Vector_For_Input.end(),
                         [For_Search](int Num) { return Num == For_Search; });
}

int Find_Average(std::vector<int> &Vector_For_Input) {
    float Average = std::accumulate(Vector_For_Input.begin(), Vector_For_Input.end(), 0) / 10
    return Average;
}

class My_Str {
private:
    std::string Str_;
public:
    My_Str(std::string Str) : Str_(Str) {};

    bool operator()(std::string Word) {
        return Word == Str_;
    }
};

int Count_Equal_Strings(std::list<My_Str>& List_For_Input, My_Str Str_El) {
    return std::count(List_For_Input.begin(), List_For_Input.end(), Str_El);
}

int CountIF_Equal_Strings(std::list<My_Str>& List_For_Input, My_Str Str_El) {
    return std::count_if(List_For_Input.begin(), List_For_Input.end(),
        [Str_El](My_Str Str) { return Str == Str_El; });
}