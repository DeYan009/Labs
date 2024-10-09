#include <iostream>
#include <iomanip>


int main() 
{
    // // ex 1
    // int A;
    // int B;
    // int C;
    // bool t1;
    // bool t2;

    // std::cin >> A;
    // std::cin >> B;
    // std::cin >> C;
    // t1 = (A + B) % C == 0;
    // t2 = C % B == 0;
    
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

    // if (std::cin.fail()) // Проверка на корректность N
    // {
    //     std::cout << "incorret N" << std::endl;
    //     return 1;
    // }

    // switch(N)
    // {
    //     case 0:std::cout << "all good" << std::endl;
    //             break;
    //     case 1:std::cout << "reading file error" << std::endl;
    //             break;
    //     case 2:std::cout << "writing file error" << std::endl;
    //             break;
    //     case 3:std::cout << "not all fields are defined" << std::endl;
    //             break;
    //     default:std::cout << "unknown N" << std::endl;
    //             break;
    // }

    // ex 3
    int x;
    std::cin >> x;
    switch(x)
    {
        case -1:std::cout <<  "Negative number" << std::endl;
                break;
        case 1:std::cout <<  "Positive number" << std::endl;
                break;
        default:std::cout << "incorrect x" << std::endl;
    }


	return 0;
}