#include "Functions.h"

int main() {

    Flower_Kl Flow1(1, "Square", {"raso", "dub", "klen"});

    std::list<Flower_Kl> New_Kls;
    std::ifstream input("input.txt");
    New_Kls = Flower_Kl::Klumba_From_File_To_List(input);


    for (Flower_Kl New_Kl: New_Kls) {
        std::cout << New_Kl;
    }

    std::multimap<Flower_Kl::Shape, Flower_Kl> Test;
    Test = Flower_Kl::From_List_To_Assosiation_Container(New_Kls);

    Flower_Kl::Return_Forms(Test);
    Flower_Kl::Return_Flowers(Flow1);

    std::cout << "\n Max Number of flowers:   " << std::endl << std::endl;
    Flower_Kl::Max_Flower_Num_Klumba(New_Kls);


    std::cout << "\n Emprty clumba:   " << std::endl << std::endl;
    Flower_Kl::Empty_Klumba("rose", New_Kls);


    std::cout << "\nNum of flowers on circle: " << std::endl << std::endl;
    std::cout << Num_Circle_Flowers(New_Kls);

    std::cout << "\nFind by number: " << std::endl << std::endl;
    Find_By_Number(New_Kls, 2);


    return 0;
}
