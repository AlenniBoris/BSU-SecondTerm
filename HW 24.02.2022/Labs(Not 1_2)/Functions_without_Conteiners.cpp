#include "Functions_without_Conteiners.h"


void Fill_List_With_Text(std::ifstream &Input_File, std::list<std::string> &List_For_Input) {
    std::copy(std::istream_iterator<std::string>(Input_File), std::istream_iterator<std::string>(),
              std::back_inserter(List_For_Input));
}

void Sort_List(std::list<std::string> &Input_List) {
    Input_List.sort();
}

void Show_Sorted_List(std::list<std::string> &Input_List) {
    Sort_List(Input_List);
    for (std::string Show_Str: Input_List) {
        std::cout << Show_Str << ' ';
    }
}

void Print_Words_With_Letter(std::list<std::string> &Input_List, char Search_Letter) {
    std::list<std::string> For_Words;
    for (std::string Find_Str: Input_List) {
        std::string Found_Str;
        bool flag = false;
        for (int i = 0; i < Find_Str.size(); ++i) {
            if (Find_Str[i] == Search_Letter) {
                flag = true;
            }
            if (flag == true) {
                Found_Str.push_back(Find_Str[i]);
            }
        }
        For_Words.push_back(Found_Str);
    }
    for (std::string Show_Str: For_Words) {
        std::cout << Show_Str << ' ';
    }
}

class Initial {
private:
    char letter_;
public:
    Initial(char Letter) : letter_(Letter) {};

    bool operator()(std::string Word) {
        return Word[0] == letter_;
    }
};

void Delete_Words_With_Letter(std::list<std::string> &Input_List, char Search_Letter) {
    std::list<std::string>::iterator it1 = std::find_if(Input_List.begin(), Input_List.end(), Initial(Search_Letter));
    std::list<std::string>::iterator it2 = std::find_if_not(it1, Input_List.end(), Initial(Search_Letter));
    Input_List.erase(it1, it2);
}
