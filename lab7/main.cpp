#include <func.hpp>
// #include <iostream>

int main() 
{
    int mas[N_Max][N_Max];
    int n = 1;
    Read(mas, n);
    if(isHaveTwoMinElements(mas, n) && isPrimeAbs(mas, n))
        Sort(mas, n);
    Write(mas, n);
	return 0;
}
