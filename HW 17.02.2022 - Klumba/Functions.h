#ifndef HW_17_02_2022___KLUMBA_FUNCTIONS_H
#define HW_17_02_2022___KLUMBA_FUNCTIONS_H


#include "Klumba.h"

    bool operator== (Flower_Kl& F_Kl, Flower_Kl& S_Kl);

    int Num_Circle_Flowers(std::list<Flower_Kl> Klumbs);

    std::list<Flower_Kl> Find_By_Number(std::list<Flower_Kl> Klumbs, int Num_Flowers);

    std::list<Flower_Kl> Find_By_Shape(std::list<Flower_Kl> Klumbs, Flower_Kl::Shape shape);

#endif //HW_17_02_2022___KLUMBA_FUNCTIONS_H
