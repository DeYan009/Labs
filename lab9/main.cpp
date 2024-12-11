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
// #include <iostream>

// int main() {
//     unsigned short number = 500; // Пример числа
//     unsigned char* bytePtr = reinterpret_cast<unsigned char*>(&number); // Указатель на байты числа

//     std::cout << "number " << number << ":\n";
//     for (size_t i = 0; i < sizeof(unsigned short); ++i) {
//         std::cout << "byte " << i << ": "  << static_cast<int>(bytePtr[i]) << std::endl;
//     }

//     return 0;
// }