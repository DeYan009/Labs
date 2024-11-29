#include <func.hpp>
#include <iostream>

int main() 
{
    int mas[N_Max][N_Max];
    int n = 1;
    Read(mas, n);
    Write(mas, n);
    std::cout << isPrimeAbs(mas, n) << std::endl;
	return 0;
}