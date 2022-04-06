#include <iostream>
#include <vector>


extern "C" void __fastcall CreateVectorB(unsigned int A[][4], int N, int M, int* B);
extern "C" int  __stdcall FindSaddlePoints(unsigned int matrix[][4], int N, int M, int* results);
extern "C" void __fastcall IntToOct(int, char*);


int main() {
	/*std::vector<int> B;*/
	const int M = 4, N = 3;
	int* B = new int[3];
	int A[M][N] = { {1,4,5},{0,4,6},{3,2,7},{0,2,0} };

	//for (int i = 0; i < M; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		std::cout << A[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}
	
	/*for (int k = 0; k < 3; k++)
	{
		int counter = 0;
		for (int t = 0; t < 4; t++)
		{
			if (A[t][k] == 0)
			{
				++counter;
				
			}
		}
		B[k] = counter;
	}*/

	
	/*__asm {
		mov eax, B
		push eax
		push N

		lea ecx, A
		mov edx, M

		call CreateVectorB

		pop ebx
		pop ebx
	}

	for (int l = 0; l < 3; l++)
	{
		std::cout << B[l] << ' ';
	}*/
	int* results = new int[20];
	__asm {
		mov eax, results
		push eax
		push N

		lea ecx, A
		mov edx, M

		call CreateVectorB

		pop ebx
		pop ebx
	}

	int number = 0x2A;
	char str[12];
	IntToOct(number, str);
	std::cout << "IntToOct = " << str << '\n';

}