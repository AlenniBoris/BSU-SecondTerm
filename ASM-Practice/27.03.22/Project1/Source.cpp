#include <iostream>

void HEX() { //в 16-ричную
	int num = 12345;
	char str1[9];
	str1[8] = 0;
	char ABC[] = "0123456789ABCDEF";
	
	__asm {
		mov ecx, 8
		mov eax, num
		beg:
			cmp ecx, 0
			jle end
				mov ebx, eax
				and ebx, 0x0000000F
				mov dl, byte ptr ABC[ebx]
				mov str1[ecx-1], dl
				shr eax, 4
				dec ecx
				jmp beg
		end:
	}
	
	std::cout << str1;
}

void OCT() { //в 8-ричную
	int num = 58;
	char str1[9];
	str1[8] = 0;
	char ABC[] = "01234567";

	__asm {
		mov ecx, 8
		mov eax, num
		beg :
		cmp ecx, 0
			jle end
			mov ebx, eax
			and ebx, 0x0000000F
			mov dl, byte ptr ABC[ebx]
			mov str1[ecx - 1], dl
			shr eax, 4
			dec ecx
			jmp beg
			end :
	}

	std::cout << str1;
}


char* StrChar(char* str, char symbol) {
	char* symb = nullptr;
	int i = 0;
	while (str[i] != symbol) {
		if (str[i] == symbol) {
			symb = &str[i];
			break;
		}
		++i;
	}
	return symb;
}

int main() {
	StrChar();
}