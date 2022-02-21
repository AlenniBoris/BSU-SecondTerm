#include "Functions.h"

int main() {
    std::ifstream file("index.txt");
    std::list<std::string> List;
    Fill_List_With_Text(file,List);



    Show_List(List);

    std::cout << std::endl;
    To_New_Container();

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


    return 0;

}
