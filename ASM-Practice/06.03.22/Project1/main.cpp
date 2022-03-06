#include "iostream"

int main() {
	
	int res_1, res_2, var1 = -30,var2 = -12 ;
	short int a = 3;
	char c = 3;
	__asm {


		movsx eax, var1;
		movsx ebx, c;
		add eax, ebx;
		imul a;
		mov res_1, eax;

		movsx eax, var2;
		imul c;

		add res_1, eax;

	}

	std::cout << "Result: " << res_1;

	return 0;
}