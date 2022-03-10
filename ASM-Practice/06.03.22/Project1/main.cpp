#include "iostream"

int main() {
	
    int a = 10, b = 4, c = -3, x = 2, result;
    _asm
    {
        mov eax, a; eax < -a
        imul eax, c; eax < -a * c
        imul eax, 2; eax < -2 * a * c
        mov edi, eax; ebx < -2 * a * c

        mov eax, b
        mov ecx, 1
        imul ecx
        idiv x
        mov esi, eax; esi < -b / x

        sub edi, esi
        sub edi, 12; edi < -2 * a * c - b / x - 12

        mov eax, c
        imul x
        add eax, a; eax < -c * x + a

        mov ebx, eax
        mov eax, edi

        idiv ebx; eax < -(2 * a * c - b / x - 12) / (c * x + a)

        mov result, eax


    }
}