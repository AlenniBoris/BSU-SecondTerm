#include "Functions.h"

int main() {
    std::ifstream file("index.txt");
    std::list<std::string> List;
    std::vector<std::string> vector;
    Fill_List_With_Text(file,List);



    Show_List(List);

    std::cout << std::endl;
    To_New_Container(List,vector);

    std::cout << std::endl;
    std::cout << Count_With_Letter(List,'f');

    std::cout << std::endl;
    Delete_With_Letter(List,'f');
    Show_List(List);

    std::cout << std::endl;
    std::cout << Count_With_Letter(List,'f');

    std::cout << std::endl;
    Show_Reverse(List);

    std::cout << std::endl;
    Print_Unique_Alphabet(file);

    std::cout << std::endl;
    Count_Double(file);

    return 0;

}
