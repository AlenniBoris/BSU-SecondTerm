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

void To_New_Container(){
    std::list<int> List_To_Copy = { 1,2,3,4 };
    std::vector<int> Vector_Copy = { 0,0,0,0 };
    std::copy(List_To_Copy.begin(), List_To_Copy.end(), Vector_Copy.begin());
    Show_Vector(Vector_Copy);
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
    std::string Words;
    std::list<std::string> Unique_Words;

    std::function isEndOfWord{
            [](char& letter){return letter == ' ';}
    };
    while(Input_File >> Words){
        std::string Letters;
        for (int i = 0; i < Words.size(); ++i) {
            if (Words[i] != ' '){
                Letters += Words[i];
            }
            Unique_Words.push_back(Letters);
        }
    }
    Unique_Words.unique();
    Unique_Words.sort();
    std::cout << "Num of unique words: " << Unique_Words.size();
    for (std::string New_Str : Unique_Words) {
        std::cout << New_Str << " ";
    }
}