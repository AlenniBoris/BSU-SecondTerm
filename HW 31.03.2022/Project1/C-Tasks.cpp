#include <iostream>


extern "C" void __fastcall IntToHex(int, char*);
extern "C" void __fastcall IntToOct(int, char*);
extern "C" void __fastcall IntToDec(int, char*);
extern "C" int __fastcall StrToInt32(char*);
extern "C" char __fastcall CharByIndex(char* str, int index);
extern "C" int __fastcall StrCompare(char* str1, char* str2);
extern "C" char __fastcall StrChar(char* str, char symbol);
extern "C" int __fastcall Max(int**, int);

int main(){
	int numb = 528; 
	char str1[9];
	char str2[11];
	char str3[33];
	char str4[] = "111";
	char str5[] = "54324577";
	char str6[] = "lalal";
	char str7[] = "lalal";

	IntToHex(numb, str1);
	std::cout << "IntToHex = " << str1 << std::endl;

	IntToOct(numb, str2);
	std::cout << "IntToOct = " << str2 << std::endl;

	IntToDec(numb, str3);
	std::cout << "IntToOct = " << str3 << std::endl;

	
	std::cout << "StrToInt32 = " << StrToInt32(str4) << std::endl;

	std::cout << "Char by index = " << CharByIndex(str5,2) << std::endl;

	std::cout << "String compare = " << StrCompare(str6, str7) << std::endl;

	char str[] = "bhbjnjola";
	char sy = 'a';

	std::cout << "String char = " << (void*)StrChar(str, sy) << std::endl;

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
		std::cout << std::endl;
	}
	std::cout << "max = " << Max(A, n) << std::endl;
	for (int i = 0; i < n; ++i)
	{
		delete[] A[i];
	}
	delete[] A;
	
	return 0;
}
