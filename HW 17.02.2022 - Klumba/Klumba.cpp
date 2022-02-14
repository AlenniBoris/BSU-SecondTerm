#include "Klumba.h"

Flower_Kl::Flower_Kl(int Num_Kl, std::string Kl_Shape = 0, std::list<std::string> Kl_Flowers = {}) {
    Klumba_Num = Num_Kl;

    if (Kl_Shape == "Square"){ Kl_Shape = Square; }
    if (Kl_Shape == "Circle"){ Kl_Shape = Circle; }
    if (Kl_Shape == "Romb"){ Kl_Shape = Romb; }

    this->Kl_Flowers.swap(Kl_Flowers);
}

int Flower_Kl::Get_Klumba_Num(){
    return Klumba_Num;
}

std::string Flower_Kl::Get_Kl_Flowers() {
    std::string String_With_Flowers = "";
    for (std::string str : Kl_Flowers) {
        String_With_Flowers+= str + ' ';
    }
    return String_With_Flowers;
}

Flower_Kl::Shape Flower_Kl::Get_Klumba_Shape() {
    return Kl_Shape;
}

std::multimap<Flower_Kl::Shape, Flower_Kl> Flower_Kl::Get_Klumbs_File(const std::string &File) {
    std::ifstream Klumba_File(File);
    std::multimap<Flower_Kl::Shape, Flower_Kl> Klumb_From_File;
    std::string Klumbs = "";

    if (Klumba_File.is_open()){
        while (std::getline(Klumba_File, Klumbs)){
            std::vector<int> For_Spaces;
            for (int i = 0; i < Klumbs.size(); ++i) {
                if (Klumbs[i] == ' '){
                    For_Spaces.push_back(i);
                }
            }
            std::list<std::string> Flow_Kl;
            for (int j = For_Spaces.size(); j > 1 ; --j) {
                Flow_Kl.push_front(Klumbs.substr(For_Spaces[j - 1] + 1, For_Spaces[j] - (For_Spaces[j - 1] + 1)));
            }
            Flower_Kl Clumba_Obj(std::stoi(Klumbs.substr(0,For_Spaces[0])), Klumbs.substr(For_Spaces[0]+1,For_Spaces[1]-(For_Spaces[0]+1)),Flow_Kl);
            Klumb_From_File.insert(std::pair<Flower_Kl::Shape, Flower_Kl>(Clumba_Obj.Get_Klumba_Shape(),Clumba_Obj));
        }
    }
    return Klumb_From_File;
}

