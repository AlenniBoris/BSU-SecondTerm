#include "Klumba.h"

int main() {
    std::multimap<Flower_Kl::Shape, Flower_Kl> mp;
    mp = Flower_Kl::Get_Klumbs_File(std::string("input.txt"));
    return 0;
}
