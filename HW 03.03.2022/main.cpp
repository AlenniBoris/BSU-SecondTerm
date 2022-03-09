#include "Polish.h"

int main() {


    std::string str;
    std::cout << "Enter equation: \n";
    std::cin >> str;
    std::cout << "result: " << Equation_instr(str);

    return 0;
}
