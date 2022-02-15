#include "Klumba.h"

Flower_Kl::Flower_Kl(int Num_Kl, std::string Shape_Kl = 0, std::list<std::string> Flowers_Kl = {}) {
    Klumba_Num = Num_Kl;

    if (Shape_Kl == "Square"){ Kl_Shape = Square; }
    if (Shape_Kl == "Circle"){ Kl_Shape = Circle; }
    if (Shape_Kl == "Romb"){ Kl_Shape = Romb; }

    this->Kl_Flowers.swap(Flowers_Kl);
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

Flower_Kl::Shape Flower_Kl::Get_Klumba_Shape() const {
    return Kl_Shape;
}

std::list<Flower_Kl> Flower_Kl::Klumba_From_File_To_List(std::ifstream &file) {
    std::list<Flower_Kl> Klumbs;
    std::list<std::string> Strings_From_File;
    std::string For_Next_String;
    while(std::getline(file,For_Next_String)){
        Strings_From_File.push_back(For_Next_String);
    }

    for(std::string line : Strings_From_File){
        std::string Num_;
        std::string Shape_;
        std::string Flowers;
        int Count_Spaces = 0;
        int i = 0;

        while(line[i] && i != line.size()){
            if (Count_Spaces == 0)
                Num_+=line[i];
            if (Count_Spaces == 1 && line[i] != ' ')
                Shape_+=line[i];
            if (Count_Spaces > 1)
                Flowers+=line[i];
            ++i;
        }

        std::list<std::string> Flowers_;
        std::string Words_;
        for (int j = 0; j < Flowers.size(); ++j) {
            if (Flowers[j] != ' '){
                Words_+=Flowers[j];
            }
            if (Flowers[j+1] == ' ' || j == (Flowers.size()-1)){
                Flowers_.push_back(Words_);
                Words_="";
            }
        }
        Klumbs.push_back(Flower_Kl(std::stoi(Num_),Shape_,Flowers_));
    }
    return Klumbs;
}

std::multimap<Flower_Kl::Shape, Flower_Kl>
Flower_Kl::From_List_To_Assosiation_Container(std::list<Flower_Kl> &Type_Kl) {
    std::multimap<Flower_Kl::Shape, Flower_Kl> Klumbs;

    for (Flower_Kl New_Kl : Type_Kl){
        Klumbs.insert(std::pair<Flower_Kl::Shape, Flower_Kl>(New_Kl.Get_Klumba_Shape(),New_Kl));
    }

    return Klumbs;
}

Flower_Kl Flower_Kl::Return_Forms(std::multimap<Flower_Kl::Shape, Flower_Kl>& container) {
    std::cout << "Shapes of your clumbs :" << std::endl;

    std::multimap<Flower_Kl::Shape, Flower_Kl>::iterator Iter;
    for (Iter = container.begin(); Iter != container.end(); ++Iter){
        bool flag = true;
        for (std::string str :  Iter->second.Kl_Flowers){
            if (str != Iter->second.Kl_Flowers.front()){
                flag = false;
                break;
            }
        }
        if (flag){
            return Iter->second;
        }
    }
    std::list<std::string> fl1 = {"dub" , "lipa"};
    Flower_Kl No_Same_Klumbs(1,"circle",fl1);
    return No_Same_Klumbs;
}

void Flower_Kl::Return_Flowers(Flower_Kl New_Kl) {
    std::cout << "Flowers from your " << std::endl;
    std::cout << New_Kl.Get_Kl_Flowers();
}
//
//std::multimap<Flower_Kl::Shape, Flower_Kl> Flower_Kl::Get_Klumbs_File(const std::string &File) {
//    std::ifstream Klumba_File(File);
//    std::multimap<Flower_Kl::Shape, Flower_Kl> Klumb_From_File;
//    std::string For_Klumbs = "";
//
//    if (Klumba_File.is_open()){
//        while (std::getline(Klumba_File, For_Klumbs)){
//            std::vector<int> For_Spaces;
//            for (int i = 0; i < For_Klumbs.size(); ++i) {
//                if (For_Klumbs[i] == ' '){
//                    For_Spaces.push_back(i);
//                }
//            }
//            std::list<std::string> Flow_Kl;
//            for (int j = For_Spaces.size(); j > 1 ; --j) {
//                Flow_Kl.push_front(For_Klumbs.substr(For_Spaces[j - 1] + 1, For_Spaces[j] - (For_Spaces[j - 1] + 1)));
//            }
//            Flower_Kl New_Clumba(std::stoi(For_Klumbs.substr(0, For_Spaces[0])), For_Klumbs.substr(For_Spaces[0] + 1, For_Spaces[1] - (For_Spaces[0] + 1)), Flow_Kl);
//            Klumb_From_File.insert(std::pair<Flower_Kl::Shape, Flower_Kl>(New_Clumba.Get_Klumba_Shape(), New_Clumba));
//        }
//    }
//    return Klumb_From_File;
//}

