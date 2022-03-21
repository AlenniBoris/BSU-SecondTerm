#include "iostream"
#include "cassert"
#include "algorithm"


void task_1() {
	unsigned int numer_ = 115, denom_ = 5627, NOD;
	assert(denom_ != 0);
	__asm {
		mov eax, numer_
		cmp eax, denom_; numer_ != denom_
		jne not_eq ; jump  den != num
			mov eax, numer_
			cdq
			idiv numer_
			mov numer_, eax; numer = 1
			mov ebx, denom_
			cdq
			idiv eax
			mov denom_, eax; denom = 1
			jmp end_
		not_eq :
			mov eax, numer_
			cmp eax, denom_;
			jg num_gr_den; jump  num > den
				beg_1 : 
					mov eax, denom_
					cmp eax, 0
					jnge end_1
					sub eax, numer_ ; denom1  = denom - numer
					cmp eax, numer_
					jl subnum_less ; jump  denom1 < numer 
						mov edx, numer_
						mov NOD, edx
						jmp end_1 
					subnum_less :
						mov edx, numer_
						mov denom_, edx ; denom <-- numer
						mov numer_, eax ; numer <-- denom1
				jmp beg_1
			end_1 :
				mov eax, denom_
				cdq
				idiv NOD
				mov denom_, eax
				mov eax, numer_
				cdq
				idiv NOD
				mov numer_, eax
				jmp end_ 
			num_gr_den : 
				beg_2:
					mov eax, numer_
					cmp eax, 0
					jnge end_2
					sub eax, denom_
					cmp eax, denom_
					jl subnum_less1
						mov edx, denom_
						mov NOD, edx
						jmp end_2
					subnum_less1:
						mov edx, denom_
						mov numer_, edx
						mov denom_, eax
				jmp beg_2
			end_2 :
				mov eax, denom_
				cdq
				idiv NOD
				mov denom_, eax
				mov eax, numer_
				cdq
				idiv NOD
				mov numer_, eax
			end_ :
	}
	std::cout << "Number: " << numer_ << '/' << denom_ << std::endl;
}
void task_2() {
	int num_ = 4654, count_ = 0, ost = 0, quot = 0;
	//CPP
	/*while (num_ != 0) {
		num_ = num_ / 2;
		count_++;
	}*/
	__asm {
		mov eax, num_
		mov edi, 0
		beg_:
		cmp eax, 0
			je end_; we compare our number with 0 
				mov ecx, 1
				imul ecx
				mov ecx, 2 ; we divide nummber by two 
				idiv ecx
				inc edi ; edi = edi + 1
				jmp beg_; we jump to the end of while
			end_ :
		mov count_, edi
	}
	std::cout << count_ << std::endl;
}
void task_3() {
	int Arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	std::sort(Arr, Arr + 10);
	int left = 0, right = 9, num = 3;
	int pos;
	//CPP
	/*int mid;
	while (left <= right) {
		mid = (right - left) / 2 + left;
		if (num == Arr[mid]) {
			std::cout << mid << std::endl;
			break;
		}
		else if (num < Arr[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}*/
	__asm {
	
	beg:
		mov ebx, right
		cmp ebx, left
		jl r_less_l
			mov eax, left
			add eax, right
			mov ecx, 1
			mul ecx
			inc ecx
			div ecx
			mov ecx, num
			cmp ecx, Arr[eax*4]
			jne neq
				mov eax, ecx
				mov pos, eax
				jmp end
			neq: 
				cmp ecx, Arr[eax * 4]
				jg num_gr
					mov ebx, eax
					sub ebx, 1
					mov right,ebx
					jmp  beg
				num_gr:
					mov edx, eax
					add edx, 1
					mov left, edx
					jmp beg
		r_less_l:
	end:				
	}
	std::cout << pos;
}
void task_4() {
	const int n = 10;
	int Arr[10] = { 0,1,1,1,2,2,3,4,5,6 };
	int max_num = 1, first = 0, length_ = 1;
	//CPP
	/*for (int i = 0; i < 10; i++)
	{
		if (Arr[i] == Arr[i + 1])
		{
			int length_ = 1;
			first = i - 1;
			int j = i;
			while (Arr[j] == Arr[i])
			{
				length_++;
				++j;
			}
			i = j;
			if (length_ > max_num)
				max_num = length_;
		}
	}*/
	__asm {
		mov ecx, 0
		beg:
		cmp ecx, n
			jge end
			mov eax, Arr[ecx * 4]
			mov ebx, Arr[ecx * 4 + 4]
			cmp eax, ebx
			mov length_, 1
			jne no_eq
			mov first, ecx
			mov ebx, ecx
			beg_ :
		mov eax, Arr[ebx * 4]
			cmp eax, Arr[ecx * 4]
			jne end_
			inc length_
			inc ebx
			jmp beg_
			end_ :
		mov ecx, ebx
			mov ebx, length_
			cmp ebx, max_num
			jle no_gr
			mov max_num, ebx
			no_gr :
	no_eq:
		inc ecx
			jmp beg
			end :
	}
	std::cout << "firts meet: " << first << " num of numbers: " << max_num << '\n';
}
void task_5() {
	int Arr[10] = { 1,1,1,2,2,3,4,5,6,6 };
	int newArr[6];
	int b = 0;
	int flag = 1;
	
	//CPP
	/*for (int j = 0; j < 10; j++)
	{
		bool flag = true;
		for (int i = 0; i <= b; i++)
		{
			if (b == 0) {
				newArr[b++] = Arr[j];
				flag = false;
				break;
			}
			else if(Arr[j] == newArr[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			newArr[b++] = Arr[j];
		}
	}
	*/

	__asm {
		mov ecx, 0
		mov eax, b
		beg :
		cmp ecx, 10
			jge end;
			mov flag, 1
			mov ebx, 0
			beg_:
		cmp ebx, eax
			jg end_;
			mov edx, Arr[ecx * 4]
			cmp eax, 0
			jne nzero_b
			mov newArr[eax * 4], edx
			inc eax
			mov flag, 0
			jmp end_
			nzero_b :

		cmp edx, newArr[ebx * 4]
			jne neq_arr
			mov flag, 0
			jmp end_
			neq_arr :

		inc ebx
			jmp beg_
			end_ :
		cmp flag, 1
			jne tr_fl
			mov newArr[eax * 4], edx
			inc eax
			tr_fl :

			inc ecx
			jmp beg
		end :
	}
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << newArr[i] << ' ';
	}
}


int main() {
	task_2();
	return 0;
}