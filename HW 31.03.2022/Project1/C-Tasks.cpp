//#include <iostream>
//#include <string.h>
//
//
//
//
//
//int minln(char* str1, char* str2) {
//	return std::min(strlen(str1), strlen(str2));
//}
//
//int StrCompare(char* str1, char* str2) {
//	int i = 0;
//	int length = strlen(str1);
//	while (i < length) {
//		if (str1[i] == str2[i]) {
//			return 0;
//		}
//		else {
//			if (str1[i] > str2[i]) {
//				return 5;
//				
//			}
//			else {
//				return -5;
//				
//			}
//		}
//		++i;
//	}
//}
//
//
//int main() {
//	char str[] = "alal;";
//	char str1[] = "abal;";
//	char symbol = 'b';
//	//StrChar(str, symbol);
//	std::cout << StrCompare(str, str1);
//
//}


#include <iostream>
extern "C" void __fastcall IntToHex(int, char*);
extern "C" void __fastcall IntToOct(int, char*);
extern "C" void __fastcall IntToDec(int, char*);

// int StrToInt32(char*);
// char* StrChar(char* str, char symbol);
// int StrCompare(char* str1, char* str2);
// char CharByIndex(char* str, int index);
extern "C" int __fastcall Max(int**, int);
int main()
{
	int numb = 58; // 2A = 0010 1010
	char str1[9];
	char str2[11];
	char str3[33];

	IntToHex(numb, str1);
	std::cout << "IntToHex = " << str1 << std::endl;

	IntToOct(numb, str2);
	std::cout << "IntToOct = " << str2 << std::endl;

	IntToDec(numb, str3);
	std::cout << "IntToOct = " << str3 << std::endl;

	int n = 5;
	int** A = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		A[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			A[i][j] = rand() % 100;
		}
	}
	int max = Max(A, n);
	std::cout << "max = " << max << std::endl;
	std::cout << "A[1][2] = " << A[1][2] << std::endl;
	for (int i = 0; i < n; ++i)
	{
		delete[] A[i];
	}
	delete[] A;
	return 0;
}
