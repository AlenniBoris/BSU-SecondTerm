#include <iostream>

//extern "C" char __fastcall StrChar(char* str, char symbol);

int Max(int** A, int a) {
	int max = 0;
	for (int i = 0; i < 5; i++)
	{

	}
	return max;
}

int main() {
	
	int n = 5;
	int** A = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		A[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			A[i][j] = rand() % 100;
			std::cout << A[i][j] << ' ';
		}
	}
	int max = Max(A, n);
	std::cout << "max = " << max << std::endl;
	for (int i = 0; i < n; ++i)
	{
		delete[] A[i];
	}
	delete[] A;

}