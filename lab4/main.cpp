// Директива препроцессора
#include <iostream>
#include <math.h>
#include <iomanip>
#include <locale>


int main() 
{
	setlocale(LC_ALL, "Rus");
    // // ex 1
    // int A;
    // int B;
    // int C;
    // bool t1;
    // bool t2;

    // std::cin >> A;
    // std::cin >> B;
    // std::cin >> C;
    // if ((A + B) % C == 0)
    //     {
    //         t1 = 1;
    //     }
    // else
    //     {
    //         t1 = 0;
    //     }
    
    // if (C % B == 0)
    //     {
    //         t2 = 1;
    //     }
    // else
    //     {
    //         t2 = 0;
    //     }
    
    // if (t1 && t2)
    // {
    //     std::cout << (A + B)/C - C/B << std::endl;
    // }
    // else if (t1 && !t2)
    // {
    //     std::cout << (A + B)/C + B * C << std::endl;
    // }
    // else
    // {
    //     std::cout << A - B + C << std::endl;
    // }

    // // ex 2
    // int N;
    // std::cin >> N;
    // switch(N + 1)
    // {
    //     case 1:std::cout << "all good" << std::endl;
    //             break;
    //     case 2:std::cout << "error file read" << std::endl;
    //             break;
    //     case 3:std::cout << "error file write" << std::endl;
    //             break;
    //     case 4:std::cout << "polya" << std::endl;
    //             break;
    //     default:std::cout << "error N" << std::endl;
    //             break;
    // }

    // ex 3
    int x;
    std::cin >> x;
    if (x == 1)
    {
        std::cout << "Positive number" << std::endl;
        return 0;
    }
    std::cout << "Negative number" << std::endl;
	return 0;
}