#include "Functions.h"
//classes ant methods

class Search{
private:
    char letter_;
public:
    Search(char Letter) : letter_(Letter) {};
    bool operator()(std::string Word){
        return Word[0] == letter_;
    }
};




//functions
void Fill_List_With_Text(std::ifstream &Input_File, std::list<std::string> &List_For_Input){
    std::copy(std::istream_iterator<std::string> (Input_File), std::istream_iterator<std::string> (),std::back_inserter(List_For_Input));
}

void Show_List(std::list<std::string> &List_For_Input){
    for (std::string For_List : List_For_Input) {
        std::cout << For_List << " ";
    }
}

std::list<std::string> Find_By_Letter_Func(std::list<std::string> &For_Search, char Search_Letter){
    std::list<std::string> Found_Words;
    Search search(Search_Letter);
    return Found_Words;
}
std::list<std::string> Find_By_Letter_Lambda(std::list<std::string> &For_Search, char Search_Letter){
    static std::list<std::string> Found_Words;
    for_each(For_Search.begin(), For_Search.end(), [Search_Letter](std::string word){
        if (word[0] == Search_Letter)
            Found_Words.push_back(word);
    });
    return Found_Words;
}

void Delete_With_Letter(std::list<std::string> &For_Search, char Search_Letter){
    std::list<std::string> Cleaned_List;
    for (std::string New_Str: For_Search) {
        if(New_Str[0] != Search_Letter){
            Cleaned_List.push_back(New_Str);
        }
    }
    For_Search = Cleaned_List;
}

int Count_With_Letter(std::list<std::string> &For_Search, char Search_Letter){
    int Counter = 0;
    for (std::string New_Str: For_Search) {
        bool Exist = false;
        for (int i = 0; i < New_Str.size(); ++i) {
            if (New_Str[i] == Search_Letter){
                Exist = true;
            }
        }
        if(Exist == true){
            ++Counter;
        }
    }
    return Counter;
}

void Show_Reverse(std::list<std::string> &List_For_Input){
    std::list<std::string>::iterator For_End = List_For_Input.end();
    --For_End;
    for (; For_End != List_For_Input.begin() ; --For_End) {
        std::cout << *For_End << " ";
    }
    std::cout << List_For_Input.front();
}
void Print_Unique_Alphabet(std::ifstream &Input_File){
    std::list<std::string> For_Unique;
    std::copy(std::istream_iterator<std::string>(Input_File), std::istream_iterator<std::string>(), std::back_inserter(For_Unique));
    For_Unique.unique();
    For_Unique.sort();
    for (std::string For_Words : For_Unique){
        std::cout << For_Words << "\n";
    }
}

void Count_Double(std::ifstream &Input_File){
    std::list<std::string> List_Str;
    std::copy(std::istream_iterator<std::string>(Input_File), std::istream_iterator<std::string>(), std::back_inserter(List_Str));
    List_Str.sort();
    std::vector<std::string> Vector_Str;
    To_New_Container(List_Str,Vector_Str);
    int First_Pos = 0;
    std::vector<int> For_Count;
    for (int i = 0; i < Vector_Str.size(); i++){
        if (Vector_Str[i] != Vector_Str[First_Pos] || i == Vector_Str.size() - 1){
            For_Count.push_back(i - First_Pos);
            First_Pos = i ;
        }
    }
    List_Str.unique();
    int i = 0;
    for (std::string string : List_Str){
        if (i != For_Count.size() - 1)
        {
            std::cout << string << " - " << For_Count[i] << "\n";
        }
        else
        {
            std::cout << string << " - " << For_Count[i] + 1 << "\n";
        }
        ++i;
    }
}
