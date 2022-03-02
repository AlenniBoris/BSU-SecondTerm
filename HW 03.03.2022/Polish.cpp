#include "Polish.h"

bool Operation(char symb){
    return symb == 'a' ||  symb == 'i';
}
bool Numbers(char symb){
    return symb >= 48 && symb <= 57;
}


int Operation_Instr(int F_number, int S_Number, char type_Operation){
    if (type_Operation == 'i'){
        if (F_number > S_Number){
            return S_Number;
        } else{
            return F_number;
        }
    }
    else{
        if (F_number > S_Number){
            return F_number;
        } else{
            return S_Number;
        }
    }
}

int Equation_instr(const std::string& equation_){
    Stack<int> For_Numbers;
    Stack<char> For_Operations;
    std::string N_Str;

    for (int i = 0; i < equation_.size(); ++i) {
        if (equation_.empty()){
            throw std::runtime_error("enter equation");
        }
        if (equation_[i] == 'm'){
            if (equation_[i+1] == 'a'){
                N_Str += 'a';
            }else{
                N_Str += 'i';
            }
            i += 2;
        } else{
            N_Str += equation_[i];
        }
    }

    for (int i = 0; i < N_Str.size(); ++i) {
        if (Numbers(N_Str[i])){
            For_Numbers.Push(N_Str[i]);
            continue;
        }
        if (Operation(N_Str[i])){
            For_Operations.Push(N_Str[i]);
            continue;
        }
        if (For_Numbers.Get_Size() == 2){
            int Eq_Res = Operation_Instr(For_Numbers.Top(), For_Numbers.Top(), For_Operations.Top());
            For_Numbers.Push(Eq_Res);
            continue;
        }
    }
    return For_Numbers.Top();
}