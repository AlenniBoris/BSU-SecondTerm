#include <iostream> 

void function(int B[][100], int capacity, int size) {
    int result;
    _asm {
        mov eax, type B
        mov result, eax
    }
    std::cout << result;
}


int main() {
    const int capacity = 100;
    int A[capacity][capacity];
    int size = 5;
    //! init a 
    //function(A, capacity, size);

    int numb = 2;
    char str2[33];
    str2[32] = 0;
    char str3[9];
    char abc[] = "0123456789ACBDEF";
    _asm {
        mov ecx, 32
        mov eax, numb
        beg :
        shr eax, 1
            jc one
            mov str2[ecx - 1], '0'
            jmp cont
            one :
        mov str2[ecx - 1], '1'
            cont :
            loop beg
    }
    _asm {
        mov ecx, 8
        mov eax, numb
        beg1 :
            mov ebx, eax
            and ebx, 0x00000000F
            mov dl, abc[ebx]
            mov str3[ecx - 1], dl
            shr eax,4
        loop beg1
    }
   /* _asm {
        mov ecx, 10
        mov eax, numb
        beg1 :
        mov ebx, eax
            and ebx, 0x000
            mov dl, abc[ebx]
            mov   str3[ecx - 1], dl
            shr eax, 4
            loop beg1
    }*/
    std::cout << str3 << std::endl;
    return 0;
}