#include "Klumba.h"

Flower_Kl::Flower_Kl(int Num_Kl, std::string Shape_Kl, std::list<std::string> Flowers_Kl) : Klumba_Num(Num_Kl),
                                                                                            Kl_Flowers(Flowers_Kl) {
    if (Shape_Kl == "Square") { Kl_Shape = Square; }
    if (Shape_Kl == "Circle") { Kl_Shape = Circle; }
    if (Shape_Kl == "Romb") { Kl_Shape = Romb; }
}

int Flower_Kl::Get_Klumba_Num() {
    return Klumba_Num;
}

std::list<std::string> Flower_Kl::Get_Kl_Flowers() {
    return Kl_Flowers;
}

Flower_Kl::Shape Flower_Kl::Get_Klumba_Shape() const {
    return Kl_Shape;
}

std::list<Flower_Kl> Flower_Kl::Klumba_From_File_To_List(std::ifstream &file) {
    std::list<Flower_Kl> Klumbs;
    std::list<std::string> Strings_From_File;
    std::string For_Next_String;
    while (std::getline(file, For_Next_String)) {
        Strings_From_File.push_back(For_Next_String);
    }

    for (std::string line: Strings_From_File) {
        std::string Num_;
        std::string Shape_;
        std::string Flowers;
        int Count_Spaces = 0;
        int i = 0;

        while (line[i] && i != line.size()) {
            if (Count_Spaces == 0) {
                Num_ += line[i];
            }
            if (Count_Spaces == 1 && line[i] != ' ') {
                Shape_ += line[i];
            }
            if (Count_Spaces > 1) {
                Flowers += line[i];
            }
            if (line[i] == ' ') {
                Count_Spaces++;
            }
            ++i;
        }

        std::list<std::string> Flowers_;
        std::string Words_;
        for (int j = 0; j < Flowers.size(); ++j) {
            if (Flowers[j] != ' ') {
                Words_ += Flowers[j];
            }
            if (Flowers[j + 1] == ' ' || j == (Flowers.size() - 1)) {
                Flowers_.push_back(Words_);
                Words_ = "";
            }
        }
        Klumbs.push_back(Flower_Kl(std::stoi(Num_), Shape_, Flowers_));
    }
    return Klumbs;
}

std::multimap<Flower_Kl::Shape, Flower_Kl>
Flower_Kl::From_List_To_Assosiation_Container(std::list<Flower_Kl> &Type_Kl) {
    std::multimap<Flower_Kl::Shape, Flower_Kl> Assosiation_Klumbs;

    for (Flower_Kl New_Kl: Type_Kl) {
        Assosiation_Klumbs.insert(std::pair<Flower_Kl::Shape, Flower_Kl>(New_Kl.Get_Klumba_Shape(), New_Kl));
    }

    return Assosiation_Klumbs;
}

std::ostream &operator<<(std::ostream &out, Flower_Kl &Klumba) {
    out << "==========" << "\n" << "Num: " << Klumba.Get_Klumba_Num() << "\n";
    switch (Klumba.Get_Klumba_Shape()) {
        case 0: {
            out << "Shape: Square" << "\n";
            break;
        }
        case 1: {
            out << "Shape: Circle" << "\n";
            break;
        }
        case 2: {
            out << "Shape: Romb" << "\n";
            break;
        }
    }
    Flower_Kl::Return_Flowers(Klumba);
    out << "==========" << "\n";

    return out;
}

bool operator==(Flower_Kl &F_Kl, Flower_Kl &S_Kl) {
    return (F_Kl.Get_Klumba_Num() == S_Kl.Get_Klumba_Num()) && (F_Kl.Get_Klumba_Shape() == S_Kl.Get_Klumba_Shape()) &&
           (F_Kl.Get_Kl_Flowers() == S_Kl.Get_Kl_Flowers());
}


void Flower_Kl::Return_Forms(std::multimap<Flower_Kl::Shape, Flower_Kl> &container) {
    std::cout << "Shapes of your clumbs :" << std::endl;

    if (container.count(Circle) > 0) {
        std::cout << "Circle ";
    }
    if (container.count(Square) > 0) {
        std::cout << "Square ";
    }
    if (container.count(Romb) > 0) {
        std::cout << "Romb ";
    }

}

void Flower_Kl::Return_Flowers(Flower_Kl New_Kl) {
    std::cout << "Flowers from your klumba: ";
    for (std::string Flowers: New_Kl.Get_Kl_Flowers()) {
        std::cout << Flowers << "\n";
    }
}

std::list<Flower_Kl> Flower_Kl::Empty_Klumba(std::string Search_Flower, std::list<Flower_Kl> Klumbs) {
    std::list<Flower_Kl> Empty_Klumbs;
    bool Flower_Dubl = false;
    bool Flower_Exist = false;
    for (Flower_Kl Fl_Bed: Klumbs) {
        for (std::string Str_Flower: Fl_Bed.Get_Kl_Flowers()) {
            if (Str_Flower == Search_Flower) {
                Flower_Exist = true;
            }
        }
        for (Flower_Kl New_Kl: Empty_Klumbs) {
            if (New_Kl == Fl_Bed) {
                Flower_Dubl = true;
            }
        }
        if (Flower_Exist == false && Flower_Dubl == false) {
            Empty_Klumbs.push_back(Fl_Bed);
        }
        Flower_Exist = false;
        Flower_Dubl = false;
    }
    return Empty_Klumbs;
}


Flower_Kl Flower_Kl::Max_Flower_Num_Klumba(std::list<Flower_Kl> Klumbs) {
    Flower_Kl Max_Num(1, "", {});
    for (Flower_Kl New_Kl: Klumbs) {
        if ((New_Kl.Get_Kl_Flowers()).size() > (Max_Num.Get_Kl_Flowers()).size()) {
            Max_Num = New_Kl;
        }
    }
    std::cout << Max_Num;
}

