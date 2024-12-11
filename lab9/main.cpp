#include <iostream>


int main() 
{
    unsigned short n;
    std::cin >> n;
    std::cout << n << std::endl;
    std::cout << &n << std::endl;
    std::cout << std::endl;
    unsigned char* nbyte =  reinterpret_cast<unsigned char*>(&n);
    std::cout << static_cast<int>(*nbyte) << std::endl;
    std::cout << static_cast<int>(*(nbyte+1)) << std::endl;
    std::cout << static_cast<int>(*(nbyte+2)) << std::endl;
	return 0;
}