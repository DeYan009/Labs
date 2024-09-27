#include <iostream>
#include <math.h>
#include <iomanip>

int main() 
{	
	const double pi = acos(-1);
	double r;
	std::cin >> r;
	double area = pi * r * r;
	std::cout << std::fixed << std::setprecision(9) << area << std::endl;
	return 0;
}
