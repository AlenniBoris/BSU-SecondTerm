#include "Functions.h"

bool operator==(Flower_Kl& F_Kl, Flower_Kl& S_Kl){
    return (F_Kl.Get_Klumba_Num() == S_Kl.Get_Klumba_Num()) && (F_Kl.Get_Klumba_Shape() == S_Kl.Get_Klumba_Shape()) && (F_Kl.Get_Kl_Flowers() == S_Kl.Get_Kl_Flowers());
}

int Num_Circle_Flowers(std::list<Flower_Kl> Klumbs){
    static int countFlowers = 0;
    std::for_each(Klumbs.begin(), Klumbs.end(), [](Flower_Kl flowerbed) -> void{
            if (flowerbed.Get_Klumba_Shape() == Flower_Kl::Circle){
                countFlowers += flowerbed.Get_Kl_Flowers().size();
            }
        }
    );
    return countFlowers;
}

std::list<Flower_Kl> Find_By_Number(std::list<Flower_Kl> Klumbs, int Num_Flowers){
    std::list<Flower_Kl> Res_Kl;
    bool duplicate = false;
    for (Flower_Kl New_kl : Klumbs)
    {
        for (Flower_Kl fl : Res_Kl)
        {
            if (fl == New_kl)
                duplicate = true;
        }
        if (New_kl.Get_Kl_Flowers().size() == Num_Flowers && duplicate == false)
            Res_Kl.push_back(New_kl);
        duplicate = false;
    }
    return Res_Kl;
}

std::list<Flower_Kl> Find_By_Shape(std::list<Flower_Kl> Klumbs, Flower_Kl::Shape shape){
    std::list<Flower_Kl> Res_Kl;
    bool duplicate = false;
    for (Flower_Kl flowerbed : Klumbs)
    {
        for (Flower_Kl fl : Res_Kl)
        {
            if (fl == flowerbed)
                duplicate = true;
        }
        if (flowerbed.Get_Klumba_Shape() == shape && duplicate == false)
            Res_Kl.push_back(flowerbed);
    }
    return Res_Kl;
}