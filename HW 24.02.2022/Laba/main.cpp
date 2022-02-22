#include "Functions_without_Conteiners.h"
#include "Functions_With_Conteiners.h"

int main() {
//    std::ifstream file("First_Input.txt");
//    std::list<std::string> First_list;
//    Fill_List_With_Text(file, First_list);
//    Print_List(First_list);
//
//    std::ifstream Numbers("Second_Input.txt");
//    std::vector<int> First_vector;
//    Fill_Vector_With_Numbers(Numbers, First_vector);
//    Print_Vector(First_vector);

    std::string str1 = "aaaa";
    My_Str Str1(str1);
    std::string str2 = "bbb";
    My_Str Str2(str2);
    std::string str3 = "11111";
    My_Str Str3(str3);
    std::string str4 = "bdadad";
    My_Str Str4(str4);
    std::string str5 = "bdadad";
    My_Str Str5(str5);
    std::list<My_Str> My_list = {Str1,Str2,Str3,Str4,Str5};

    std::string str6 = "bdadad";
    My_Str Str6(str6);

    Count_Equal_Strings(My_list,Str6);

    return 0;
}
