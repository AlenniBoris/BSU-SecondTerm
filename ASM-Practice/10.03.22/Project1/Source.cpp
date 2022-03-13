#include <iostream>
#include <iomanip>
int main()
{
    /*const int n = 5;
    int a[n] = { 0,1,2,3,4 };
    int result = 0;*/
    //for (int i = 0; i < n; i++)
    //{
    //  result += a[i];
    //}
    //std::cout << result << '\n';

    /*_asm
    {
        mov eax, 0
        mov ecx, n; counter
        met_start_l :
        add eax, a[ecx * 4 - 4]
            loop met_start_l
            mov result, eax
    }
    std::cout << "sum " << result << '\n';

    _asm
    {
        mov eax, 0; eax = result
        mov ecx, 0; cl = i
        met_start :
        cmp ecx, n; check
            jnl met_end
            add eax, a[ecx * 4]
            inc ecx
            jmp met_start
            met_end :
        mov result, eax

    }
    std::cout << "sum " << result << '\n';

    int* b = new int[n];
    std::copy(a, a + n, b);
    _asm
    {
        mov eax, 0; eax = result
        mov ecx, 0; cl = i
        mov ebx, b
        met_start1 :
        cmp ecx, n; check
            jnl met_end1
            add eax, [ebx][ecx * 4]
            inc ecx
            jmp met_start1
            met_end1 :
        mov result, eax

    }
    std::cout << "sum " << result << '\n';

    _asm
    {
        mov ebx, n
        dec ebx
        imul ebx, 4
        push a
        push a[ebx]
        pop a
        pop a[ebx]
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << '\n';
    }*/

    /*_asm
    {
      mov ebx, n
      dec ebx
      imul ebx, 4
      mov eax, b
      push [eax]
      push[eax][ebx]
      pop  [eax]
      pop[eax][ebx]
    }
    for (int i = 0; i < n; i++)
    {
      std::cout << b[i] << '\n';
    }*/


    int x = 12;
    _asm
    {
        mov eax, x
        test eax, 1
        jz not_p; переход, если четное
        ; действия, если нечетное
        jmp end_
        not_p :
        ; действия, если четное
            end_ :
    }
}