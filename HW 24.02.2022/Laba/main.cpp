#include "Functions_without_Conteiners.h"
#include "Functions_With_Conteiners.h"

int main() {
//    std::ifstream file("First_Input.txt");
//    std::list<std::string> First_list;
//    Fill_List_With_Text(file,First_list);
//
//    Print_List(First_list);
//
//    Delete_Words_With_Letter(First_list,'d');
//    std::cout << std::endl;
//    Print_List(First_list);
//
//    std::cout << std::endl;
//    Show_Sorted_List(First_list);
//
//    std::cout << std::endl;
//    Print_Words_With_Letter(First_list, 'b');

    std::ifstream Numbers("Second_Input.txt");
    std::vector<int> First_vector;
    Fill_Vector_With_Numbers(Numbers,First_vector);
    Print_Vector(First_vector);

    return 0;
}
