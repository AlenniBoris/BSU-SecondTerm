#include <iostream>
#include <iomanip>
#include <cmath>

extern "C"
{
	double __cdecl task_1(double, double);
	double __cdecl task_2(double, double, double);
	double __cdecl task_3(double);
}

double get_PI()
{
	double pi;
	__asm
	{
		fldpi
		fstp pi
	}
	return pi;
}

int main() {
	double x = 4.055;
	double y = 11.755;

	std::cout << "z = " << std::setprecision(20) << task_1(x, y) << std::endl;
	std::cout << "cpp check : " << std::setprecision(20) << ((x * x) * (tan(x / y))) + ((y * y) * (cos(x/y) / sin(x / y))) <<  std::endl;


	double epsilon = 0.0000000123;
	double pi = get_PI()/12;

	std::cout << "pi check : " << std::setprecision(20) << pi << std::endl;
	std::cout << "PI = " << std::setprecision(20) << task_3(epsilon) << std::endl; 


	double f_b = -12.515;
	double s_b = 1.755;
	std::cout << "Root = " << std::setprecision(20) << task_2(epsilon, f_b , s_b) << std::endl;

}
