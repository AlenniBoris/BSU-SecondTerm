#include "Klumba.h"

int main() {
    std::string str = "Square";
    std::string str1 = "Romb";
    std::string str2 = "Romb";
    std::list<std::string> flow = {"rose", "dub", "bebbe"};
    std::list<std::string> flow1 = {"ros111e", "ub", "aSDASD"};
    std::list<std::string> flow2 = {"ro434434se", "dFWFEFEWFub", "bebASDASDe"};
    Flower_Kl fl(1,str,flow);
    Flower_Kl fl1(2,str1,flow1);
    Flower_Kl fl2(3,str2,flow2);

    std::list<Flower_Kl> New_Kl = {fl,fl1,fl2};


//    container.insert(Pair("Square", fl));
//    container.insert(Pair("Square", fl1));
//    container.insert(Pair("Square", fl2));


//    Flower_Kl::Return_Forms(New_Kl);
//    Flower_Kl::Return_Flowers(fl1);


    return 0;
}
