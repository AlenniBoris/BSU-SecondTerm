#include "iostream"

int comp(const int*, const int*);

int main() {
	/*char a = 127;
	short int b = 4;
	int c = 5, Ovrfl;
	int res1;
	char var = 0xf1;

	std::cout << "cpp solution : " << (a * b) + (a * c) + (b * c) << std::endl;

	__asm {
		movsx eax, a
		movsx ebx, b
		movsx ecx, c
		imul ebx
		mov edi, eax; a* b
		movsx eax, a
		imul ecx
		mov esi, eax; a* c
		movsx eax, b
		imul ecx
		mov res1, eax; b*c
		add res1, edi
		add res1 , esi

		jno OF_0
			mov Ovrfl, 1
			jmp end_
			OF_0 :
				mov Ovrfl, 0
		end_ :
	}
	std::cout <<"Asm: " << res1 << std::endl;
	std::cout <<"overflow: " <<  Ovrfl << std::endl;

	char a1 = -15;
	std::cout << (int)a1 << std::endl;
	std::cout << var << std::endl;*/


	int A[] = { 2, 7, -3, 5 };
	std::qsort(A, std::size(A), sizeof(int), (int(*) (const void*, const void*)) comp);
	for (int i = 0; i < std::size(A); i++)
	{
		std::cout << A[i] << ' ';
	}
	int s_num = 18;
	//std::qsort();
	std::cout<<"Found: " << std::bsearch(&s_num, A, std::size(A), sizeof(int), (int(*) (const void*, const void*)) comp);
}

int comp(const int* i, const int* j)
{
	return *i - *j;
}


