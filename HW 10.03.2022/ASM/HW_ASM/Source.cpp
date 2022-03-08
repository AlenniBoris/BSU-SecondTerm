#include <iostream>

void Change_words3_1() {
	short int F_w = 1, S_w = 2;
	
	std::cout << "Before swap: " << F_w << " " << S_w << std::endl;

	_asm {
		mov ax, F_w
		mov bx, S_w
		mov F_w, bx
		mov S_w, ax
	}

	std::cout << "After swap: " << F_w << " " << S_w << std::endl;
}

void Solve_equation4() {
	int a = 4, b = 22, Rem_part, Int_part;

	if (a == 0) {
		throw std::runtime_error("not zero a");
	}

	_asm
	{
		mov eax, b
		neg eax
		mov ebx, a
		mov ecx, 1
		imul ecx
		idiv a
		mov Int_part, eax
		mov Rem_part, edx
	}

	std::cout << "integer part: " << Int_part << std::endl;
	std::cout << "remnant part: " << Rem_part << std::endl;
}

void Solve_equation5() { //ֿמסמלüענועü ןמחזו ושו נאח
	int a = 100, b = 10, c = 10, x;
	int res1, res2, res;

	std::cout << "Enter some integer x: " << std::endl;
	std::cin >> x;

	_asm {

		mov eax, x
		sub eax, 12
		mov res1, eax

		mov eax, c
		imul x
		add eax, a
		imul res1
		mov res2, eax
		
		mov eax, 2
		imul a
		imul c
		sub eax, b
		idiv res2	
		mov res, eax

	}

	std::cout << "Your result: " << res << std::endl;
}

void Change_bytes6() {
	short int a = 7;

	std::cout << "Before changing: " << a << std::endl;

	_asm {
		mov ax, a
		
		mov bl, al
		mov al, ah
		mov ah, bl

		mov a, ax
	}

	std::cout << "After changing: " << a << std::endl;

}

void Mul_32_Overflow7() {
	int a = 2, b = 5, res, Ovrfl;
	
	_asm {
		mov eax, a
		imul b
		mov res, eax

		jno OF_0
		mov Ovrfl, 1
		jmp end_
		OF_0:
		mov Ovrfl, 0
			end_:
	}

	std::cout << "result: " << res << std::endl;
	std::cout << "overflow: " << Ovrfl << std::endl;

}

void Count_sum8() {
	char a = 10;
	short int b = 5;
	int c = 5, sum1, sum2, sum3;

	_asm {
		movsx eax, a
		movsx ebx, b
		mov ecx, 1
		imul ecx
		idiv ebx
		mov sum1, eax

		mov eax, ebx
		mov ebx, c
		idiv ebx
		mov sum2, eax

		mov eax, c
		movsx ebx, a
		idiv ebx
		mov sum3, eax


		add sum1, eax
		mov ecx, sum2
		add sum1, ecx

	}

	std::cout << "result: " << sum1 << std::endl;

}

void Find_degree9() {
	int Deg_n = 2, res;

	_asm {
		mov eax, 1
		movsx cl, Deg_n
		shl eax, cl
		mov res, eax
	}

	std::cout << "result: " << res << std::endl;
}

void Get_bit_def1() {
	char Bit_num = 2;
	int Num_ = 13;
	int Bit_;

	_asm {
		mov cl, Bit_num
		mov eax, Num_
		shr eax, cl
		mov Num_, eax

		beg_:
		jnc CF_0
			mov Bit_, 1
			jmp end_
			CF_0:
		mov Bit_,0
			end_:
	}

	std::cout << "Bit def: " << Bit_ << std::endl;
}

int main() {
	Get_bit_def1();
}