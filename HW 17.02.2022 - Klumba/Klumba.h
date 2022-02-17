#ifndef HW_17_02_2022___KLUMBA_KLUMBA_H
#define HW_17_02_2022___KLUMBA_KLUMBA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <string>
#include <map>
#include <functional>


class Flower_Kl {
public:
    int Klumba_Num;
    enum Shape {
        Square = 0,
        Circle = 1,
        Romb = 2
    };
    Shape Kl_Shape;
    std::list<std::string> Kl_Flowers;

public:
    Flower_Kl(int Num_Kl, std::string Shape_Kl, std::list<std::string> Flowers_Kl);

    ~Flower_Kl() = default;

    int Get_Klumba_Num();

    std::list<std::string> Get_Kl_Flowers();

    Shape Get_Klumba_Shape() const;

    static std::list<Flower_Kl> Klumba_From_File_To_List(std::ifstream &file);

    static std::multimap<Flower_Kl::Shape, Flower_Kl> From_List_To_Assosiation_Container(std::list<Flower_Kl> &Type_Kl);

    static void Return_Forms(std::multimap<Flower_Kl::Shape, Flower_Kl> &container);

    static void Return_Flowers(Flower_Kl New_Kl);

    static std::list<Flower_Kl> Empty_Klumba(std::string flower, std::list<Flower_Kl> Klumbs);

    static Flower_Kl Max_Flower_Num_Klumba(std::list<Flower_Kl> flowerbeds);

    friend std::ostream &operator<<(std::ostream &out, Flower_Kl &Klumba);
};

bool operator==(Flower_Kl &F_Kl, Flower_Kl &S_Kl);


#endif //HW_17_02_2022___KLUMBA_KLUMBA_H
