#include "iostream"
#include "cassert"


void task_1() {
	int numer_ = -115, denom_ = 5, NOD;
	assert(denom_ > 0);
	assert(numer_ > 0);
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
void task_4() {}
void task_5() {}


int main() {
	task_4();
}