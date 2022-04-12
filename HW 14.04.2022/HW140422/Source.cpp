#include <iostream>
#include <iomanip>
#include <cmath>

extern "C"
{
	double __cdecl task_1(double, double);
}


int main() {
	double x = 4.055;
	double y = 11.755;

	std::cout << "z = " << std::setprecision(20) << task_1(x, y) << "\n";
	std::cout << "cpp check : " << std::setprecision(20) << ((x * x) * (tan(x / y))) + ((y * y) * (cos(x/y) / sin(x / y)));

}


//fdiv st(0), st(1)
//fptan; tan - st(1)
//
//fld x; tg - 2
//fmul st(0), st(0); tg - 1
//fmul st(0), st(2); x ^ 2 * tg - 0
//
//fld y
//fld x; x ^ 2 * tg - 2
//
//fdiv st(0), st(1)
//fptan
//fdiv st(0), st(1); cot(x / y) - 0
//
//fld y; cot(x / y) - 1
//fmul st(0), st(0)
//fmul st(0), st(1); y ^ 2 * cot - 0
//
//fadd st(0), st(3)
