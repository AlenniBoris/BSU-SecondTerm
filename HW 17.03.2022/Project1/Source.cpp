#include "iostream"
#include "cassert"


void task_1() {
	unsigned int numer_ = 115, denom_ = 8954, NOD;
	assert(denom_ != 0);
	__asm{
		mov eax, numer_
		cmp eax, denom_; numer_ != denom_
		jne not_eq ; прыгать если они не равны
			; Операции если они равны
			mov eax, numer_
			cdq
			idiv numer_
			mov numer_, eax
			mov ebx, denom_
			cdq
			idiv eax
			mov denom_, eax
			jmp end_;заканчивает прогу
		not_eq :
			mov eax,numer_
			cmp eax, denom_;
			jg num_gr_den; прыгает, если числитель больше знаменателя
			beg_1:
					mov eax, denom_
					cmp eax, 0
					jnge end_1
						sub eax, numer_
						cmp eax, numer_
						jl subnum_less
							mov edx, numer_
							mov NOD, edx
							jmp end_1
						subnum_less:
							mov edx, numer_
							mov denom_, edx
							mov numer_, eax
							jmp beg_1
				end_1:
					mov eax, denom_
					cdq
					idiv NOD
					mov denom_, eax
					mov eax, numer_
					cdq
					idiv NOD
					mov numer_, eax
				jmp end_
			num_gr_den:
				beg_2:
					mov eax, numer_
					cmp eax, 0
					jnge end_2
						sub eax, denom_
						cmp eax, denom_
						jl subnum_less1
							mov edx,  denom_
							mov NOD, edx
							jmp end_2
						subnum_less1 :
							mov edx, denom_
							mov numer_, edx
							mov denom_, eax
							jmp beg_2
				end_2:
					mov eax, denom_
					cdq
					idiv NOD
					mov denom_, eax
					mov eax, numer_
					cdq
					idiv NOD
					mov numer_, eax
		end_:
	}
	std::cout << "Number: " << numer_ << '/' << denom_ << std::endl;
}
void task_2(){
	int num_ = 46, count_ = 0;
	__asm {
		mov eax, num_
		mov edi, 0
		beg_:
		cmp eax, 0
		je end_; прыгает если не равно 0
			mov ecx, 1
			imul ecx
			mov ecx, 2
			idiv ecx
			inc edi
			jmp beg_
		end_:
		mov count_, edi
	}
	std::cout << count_ << std::endl;
}
void task_3() {}
void task_4() {
	int Arr[10] = { 1,2,3,3,4,4,4,5,9,10 };
	int max_num = 1, first = 0, length = 1;
	__asm {
		mov ecx, 0
		beg:
		cmp ecx, 10
		jge end
			mov eax, Arr[ecx*4]
			mov ebx, Arr[ecx*4 + 4]
			cmp eax, ebx
			mov length, 1
			jne not_found_eq; прыгает если не находит равные элементы
				mov first, ecx
				mov ebx, ecx
				beg_:
					mov eax, Arr[ebx*4]
					cmp eax, Arr[ecx*4]
					jne end_
						inc length
						inc ebx
						jmp beg_
				end_:
				mov ecx, ebx
				mov ebx, length
				cmp ebx,max_num
				jle max_l
					mov max_num, ebx
				max_l:
					inc ecx
			not_found_eq:
				inc ecx
				jmp beg
		end:
	}
}
void task_5() {
	int Arr[10] = { 1,1,1,2,2,3,4,5,6,6 };
	int newArr[6];
	int b = 0;
	int flag = 1;
	__asm {
		mov ecx, 0
		mov eax, b
		beg:
		cmp ecx, 10
		jge end; переход в конец когда i=10
			mov flag, 1
			mov ebx, 0
			beg_:
				cmp ebx, eax
				jg end_; переход в конец когда j>b
					mov edx, Arr[ecx*4]
					cmp eax,0 
					jne nzero_b
						mov newArr[eax*4], edx
						inc eax
						mov flag, 0
						jmp end_
					nzero_b:

					cmp edx, newArr[ebx*4]
					jne neq_arr
						mov flag, 0
						jmp end_
					neq_arr:

				inc ebx		
				jmp beg_
			end_:
			cmp flag, 1
			jne tr_fl
				mov newArr[eax*4], edx
				inc eax
			tr_fl:

		inc ecx
		jmp beg
		end:

	}
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << newArr[i] << ' ';
	}
}


int main() {

	task_5();
	
}