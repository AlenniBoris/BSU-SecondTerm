#include "iostream"
#include <algorithm>

//task 1-3 in h/w 17.03.2022

void task5() {
	int a[6] = { 1,2,3,4,5,6 };
	int b[5] = { 7,8,9,10,11 };
	int c[11];
	for (int i = 0; i < 6; i++)
	{
		c[i] = a[i];
	}
	for (int i = 6; i < 11; i++)
	{
		c[i] = b[i - 6];
	}
	for (int i = 0; i < 11; i++)
	{
		std::cout << c[i] << ' ';
	}
}

void task4() {
	int a[6] = { 3,3,4,4,5,5 };
	int count = 1, j;
	
	for (int i = 1; i < 6; ++i) {
		for (j = 0; j < i; ++j){
			if (a[i] == a[j]){
				break;
			}
		}
		if (j == i) {
			count++;
		}	
	}
	std::cout << count << std::endl;

	int b[4];
	b[0] = count;
	int current = 1;
	for (int i = 0; i < 6; ++i)
	{
		bool flag = false;
		for (int j = 1; j < current; ++j)
		{
			if (b[j] == a[i])
				flag = true;
		}
		if (!flag)
		{
			b[current] = a[i];
			++current;
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		std::cout << b[i] << std::endl;
	}

}

//ASM

int Find_max(int first, int second) {
	return std::max(first, second);
}

void task_1(){
	const char* str1 = "1";
	int length1 = std::strlen(str1);
	const char* str2 = "2";
	int length2 = std::strlen(str2);
	int bord = Find_max(length1, length2);
	int i = 0;
	/*while (i < bord){
		if (str1[i] != str2[i]) {
			std::cout << 0; 
			break;
		}
		++i;
	}*/
	int flag = 1;
	__asm {
		beg:
			mov ecx, i
			cmp ecx, bord
			jge gr_bord
				mov eax, str1[ecx]
				cmp eax, str2[ecx]
				je eq_symb 
					mov edx, flag
					mov ebx, 0 ; 0 <=> !=
					mov flag, ebx
					jmp end
				eq_symb:
				inc ecx	
			gr_bord:
		end:
	}
	std::cout << flag;
}

void task_2() {
	const int n = 3;
	int a[n][n] = {
		{-10,5,0},
		{0,10,10},
		{122,1022,333} };
	int res = 0;
	/*for (int i = 0; i < n ; i++)
	{
		res += a[i][i];
	}*/
	/*int i = 0;
	while (i < n) {
		res += a[i][i];
		i++;
	}*/
	int i = 0;
	__asm {
		mov ecx, i
		beg:
			cmp ecx, n
			jge gr_or_eq
				mov edi, ecx //i*4
				imul edi, 4
				mov esi, n//n
				imul esi, edi//n*i*4
				add esi, edi//n*i*4 + i*4

				mov eax, res
				add eax, a[esi]	
				mov res, eax

				inc ecx
				jmp beg
				gr_or_eq :
		end:
	}
	std::cout << res;
}

int main() {
	task_2();
	return 0;
}