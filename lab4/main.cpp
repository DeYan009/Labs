// Директива препроцессора
#include <iostream>
#include <math.h>
#include <iomanip>
#include <locale>


int main() 
{
	setlocale(LC_ALL, "Rus");
    // std::cout << "куку" << std::endl;
    int A;
    int B;
    int C;
    bool t1;
    bool t2;

    std::cin >> A;
    std::cin >> B;
    std::cin >> C;
    if ((A + B) % C == 0)
        {
            t1 = 1;
        }
    else
        {
            t1 = 0;
        }
    
    if (C % B == 0)
        {
            t2 = 1;
        }
    else
        {
            t2 = 0;
        }
    
    if (t1 && t2)
    {
        std::cout << (A + B)/C - C/B << std::endl;
    }
    else if (t1 && !t2)
    {
        std::cout << (A + B)/C + B * C << std::endl;
    }
    else
    {
        std::cout << A - B + C << std::endl;
    }
    
    // std::cout << A + B << std::endl;
    // std::cout << B / A << std::endl;
    // std::cout << C - C << std::endl;
	return 0;
}