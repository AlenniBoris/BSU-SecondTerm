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
protected:
    int Klumba_Num;
    Shape Kl_Shape;
    std::list<std::string> Kl_Flowers;

public:
    Flower_Kl(int Num_Kl, std::string Shape_Kl, std::list<std::string>);
    ~Flower_Kl() = default;

    int Get_Klumba_Num();
    std::string Get_Kl_Flowers();
    Shape Get_Klumba_Shape() const;

    std::list<Flower_Kl> Klumba_From_File_To_List(std::ifstream &file);
    std::multimap<Flower_Kl::Shape, Flower_Kl> From_List_To_Assosiation_Container(std::list<Flower_Kl> &Type_Kl);

    static Flower_Kl Return_Forms(std::multimap<Flower_Kl::Shape, Flower_Kl>& container);
    static void Return_Flowers(Flower_Kl New_Kl);



//    static std::multimap<Flower_Kl::Shape, Flower_Kl> Get_Klumbs_File(const std::string &File);


    enum Shape{
        Square = 0,
        Circle = 1,
        Romb = 2
    };
};



#endif //HW_17_02_2022___KLUMBA_KLUMBA_H
