#include "Functions.h"

int main() {
    std::list<Flower_Kl> New_Kls;
    std::ifstream input("input.txt");
    New_Kls =  Flower_Kl::Klumba_From_File_To_List(input);
    for (Flower_Kl New_Kl : New_Kls){
        std::cout << New_Kl;
    }

    std::multimap<Flower_Kl::Shape, Flower_Kl> Test;
    Test = Flower_Kl::From_List_To_Assosiation_Container(New_Kls);
    std::cout << " Forms Test:   " << std::endl << std::endl;
    Flower_Kl::Return_Forms(Test);

    std::cout << "\n Max Number of flowers:   " << std::endl << std::endl;
    Flower_Kl::Max_Flower_Num_Klumba(New_Kls);

    std::cout << "\n Klumba by nmber:   " << std::endl << std::endl;


    return 0;
}
