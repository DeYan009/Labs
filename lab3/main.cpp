#include <iostream>
#include <math.h>
#include <iomanip>
#include <typeinfo>
#include <limits>
#include <locale>
#include <windows.h>

int main() 
{
	SetConsoleOutputCP(CP_UTF8);
    long long x;
    long long i;
    std::cin >> x;
    std::cin >> i;
    std::cout << (x |= (1 << i)) << std::endl;
	return 0;
}