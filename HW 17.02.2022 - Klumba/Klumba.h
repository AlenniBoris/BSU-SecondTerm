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
    enum Shape{
        Square,
        Circle,
        Romb
    };
    int Klumba_Num;
    Shape Kl_Shape;
    std::list<std::string> Kl_Flowers;
public:
    Flower_Kl(int Num_Kl, std::string Kl_Shape, std::list<std::string>);
    ~Flower_Kl() = default;

    int Get_Klumba_Num();
    std::string Get_Kl_Flowers();
    Shape Get_Klumba_Shape();

    static std::multimap<Flower_Kl::Shape, Flower_Kl> Get_Klumbs_File(const std::string &File);


};



#endif //HW_17_02_2022___KLUMBA_KLUMBA_H
