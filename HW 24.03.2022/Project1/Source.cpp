#include "iostream"
#include "algorithm"
#include "cassert"


void task1() {
	unsigned int numer_ = 15, denom_ = 5, NOD = 0;
	int def1 = 0;
	assert(denom_ != 0);
	if (numer_ == denom_) {
		numer_ = 1;
		denom_ = 1;
	}
	else {
		if (numer_ < denom_) {
			while (denom_ > 0) {
				def1 = denom_ - numer_;
				if (def1 > numer_) {
					NOD = numer_;
					break;
				}
				else {
					denom_ = numer_;
					numer_ = def1;
				}
			}
		}
		else {
			while (numer_ > 0) {
				def1 = numer_ - denom_;
				if (def1 > denom_) {
					NOD = denom_;
					break;
				}
				else {
					numer_ = denom_;
					denom_ = def1;
				}
			}
		}
		numer_ = numer_ / NOD;
		denom_ = denom_ / NOD;
	}
	std::cout << numer_ << '/' << denom_;
}

void task2() {
	int num_ = 4654, count_ = 0, ost = 0, quot = 0;
	//CPP
	while (num_ != 0) {
		num_ = num_ / 2;
		count_++;
	}
}

void task3() {
	int Arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	std::sort(Arr, Arr + 10);
	int left = 0, right = 9, num = 3;
	int pos;
	//CPP
	int mid;
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
	}
}

void task5() {
	int a[6] = { 1,2,3,4,5,6 };
	int b[5] = { 7,8,9,10,11 };
	int c[11];
	for (int i = 0; i < 6; i++)
	{
		c[i] = a[i];
	}
	for (int i = 6; i < 11; i++)
	{
		c[i] = b[i - 6];
	}
	for (int i = 0; i < 11; i++)
	{
		std::cout << c[i] << ' ';
	}
}

void task4() {
	int a[6] = { 3,3,4,4,5,5 };
	int count = 1, j;
	
	for (int i = 1; i < 6; ++i) {
		for (j = 0; j < i; ++j){
			if (a[i] == a[j]){
				break;
			}
		}
		if (j == i) {
			count++;
		}	
	}
	std::cout << count << std::endl;

	int b[4];
	b[0] = count;
	int current = 1;
	for (int i = 0; i < 6; ++i)
	{
		bool flag = false;
		for (int j = 1; j < current; ++j)
		{
			if (b[j] == a[i])
				flag = true;
		}
		if (!flag)
		{
			b[current] = a[i];
			++current;
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		std::cout << b[i] << std::endl;
	}

}

//ASM

int Find_min(int first, int second) {
	return std::min(first, second);
}

void task_1(){
	const char* str1 = "1aaaa";
	int length1 = std::strlen(str1);
	const char* str2 = "1";
	int length2 = std::strlen(str2);
	int bord = Find_min(length1, length2);
	int i = 0;
	/*while (i < bord){
		if (str1[i] != str2[i]) {
			std::cout << 0; 
			break;
		}
		++i;
	}*/
	int flag = 1;
	__asm {
		beg:
			mov ecx, i
			cmp ecx, bord
			jge end
				mov eax, str1[ecx]
				cmp eax, str2[ecx]
				je eq_symb 
					mov edx, flag
					mov ebx, 0 ; 0 <=> !=
					mov flag, ebx
					jmp end
				eq_symb:
				inc ecx	
		end:
	}
	std::cout << flag;
}

void task_2() {
	const int n = 3;
	int a[n][n] = {
		{-10,5,0},
		{0,10,10},
		{122,1022,333} };
	int res = 0;
	/*for (int i = 0; i < n ; i++)
	{
		res += a[i][i];
	}*/
	/*int i = 0;
	while (i < n) {
		res += a[i][i];
		i++;
	}*/
	int i = 0;
	__asm {
		mov ecx, i
		beg :
			cmp ecx, n
			jge gr_or_eq
				mov edi, ecx //i*4
				imul edi, 4
				mov esi, n//n
				imul esi, edi//n*i*4
				add esi, edi//n*i*4 + i*4

				mov eax, res
				add eax, a[esi]
				mov res, eax

				inc ecx
				jmp beg
			gr_or_eq :
		end:
	}
	std::cout << res;
}

void task_3() {
	int n = 3;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
		
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> a[i][j];
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			std::cout << a[i][j] << ' ';
		}
	std::cout << std::endl;
	
	int res = 0;
	/*for (int i = 0; i < n ; i++)
	{
		res += a[i][i];
	}*/
	/*int i = 0;
	while (i < n) {
		res += a[i][i];
		i++;
	}
	std::cout << res;*/
	int i = 0;
	__asm {
		mov ecx, i
		mov edx, a

		beg :
		cmp ecx, n
			jge end
			mov eax, [edx][ecx * 4]
			mov ebx, [eax][ecx * 4]
			add res, ebx

			inc ecx
			jmp beg
		end :
	}
	std::cout << res;
}


int main() {
	task1();
	return 0;
}