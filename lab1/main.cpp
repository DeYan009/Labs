// Директива препроцессора
#include <iostream>
#include <math.h>
#include <iomanip>
#include <typeinfo>
#include <limits>
#include <locale>


int main() 
{
	setlocale(LC_ALL, "Rus");
	// Типы данных
	// 1. Целочисленные
	// - char, 1 байт, -128..127
	// - short, 2 байта, -32768..32767
	// - int, 4 байта, -2^31 .. 2^31-1
	// - long long, 8 байт, -2^63 .. 2^63-1
	// - unsigned int, 4 байт, 0 .. 2^32-1
	// 2. Символьные
	// - char, 1 байт, -128..127
	// 3. Вещественные типы
	// - float, 4 байта, 6-7 цифр
	// - double, 8 байтов, 15-16 цифр 
	// 4. Логический тип
	// - bool, 1 байт, true/false

	// Арифметические операции
	// +, -, *, /, %, +=, -=, ++, --
	// Встроенные функции
	// pow, sqrt, sin, cos, tan, atan
	// (int)c - приведение типа из char в int, c-style cast

	//const double pi = acos(-1);
	std::cout << "Тип: " << "char" << std::endl;
    std::cout << "Размер: " << sizeof(char) << " байт" << std::endl;
    std::cout << "Минимальное значение: " << static_cast<int>(std::numeric_limits<char>::min()) << std::endl;
    std::cout << "Максимальное значение: " << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;
    std::cout << std::endl;

	std::cout << "Тип: " << "short" << std::endl;
    std::cout << "Размер: " << sizeof(short) << " байт" << std::endl;
    std::cout << "Минимальное значение: " << static_cast<int>(std::numeric_limits<short>::min()) << std::endl;
    std::cout << "Максимальное значение: " << static_cast<int>(std::numeric_limits<short>::max()) << std::endl;
    std::cout << std::endl;

	std::cout << "Тип: " << "int" << std::endl;
    std::cout << "Размер: " << sizeof(int) << " байт" << std::endl;
    std::cout << "Минимальное значение: " << static_cast<int>(std::numeric_limits<int>::min()) << std::endl;
    std::cout << "Максимальное значение: " << static_cast<int>(std::numeric_limits<int>::max()) << std::endl;
    std::cout << std::endl;

	std::cout << "Тип: " << "long long" << std::endl;
    std::cout << "Размер: " << sizeof(long long) << " байт" << std::endl;
    std::cout << "Минимальное значение: " << static_cast<long long>(std::numeric_limits<long long>::min()) << std::endl;
    std::cout << "Максимальное значение: " << static_cast<long long>(std::numeric_limits<long long>::max()) << std::endl;
    std::cout << std::endl;

	std::cout << "Тип: " << "unsigned int" << std::endl;
    std::cout << "Размер: " << sizeof(char) << " байт" << std::endl;
    std::cout << "Минимальное значение: " << static_cast<unsigned int>(std::numeric_limits<unsigned int>::min()) << std::endl;
    std::cout << "Максимальное значение: " << static_cast<unsigned int>(std::numeric_limits<unsigned int>::max()) << std::endl;
    std::cout << std::endl;

	std::cout << "Тип: " << "float" << std::endl;
    std::cout << "Размер: " << sizeof(char) << " байт" << std::endl;
    std::cout << "Минимальное значение: " << static_cast<float>(std::numeric_limits<float>::min()) << std::endl;
    std::cout << "Максимальное значение: " << static_cast<float>(std::numeric_limits<float>::max()) << std::endl;
    std::cout << std::endl;

	std::cout << "Тип: " << "double" << std::endl;
    std::cout << "Размер: " << sizeof(char) << " байт" << std::endl;
    std::cout << "Минимальное значение: " << static_cast<double>(std::numeric_limits<double>::min()) << std::endl;
    std::cout << "Максимальное значение: " << static_cast<double>(std::numeric_limits<double>::max()) << std::endl;
    std::cout << std::endl;

	std::cout << "Тип: " << "bool" << std::endl;
    std::cout << "Размер: " << sizeof(char) << " байт" << std::endl;
    std::cout << "Минимальное значение: " << static_cast<bool>(std::numeric_limits<bool>::min()) << std::endl;
    std::cout << "Максимальное значение: " << static_cast<bool>(std::numeric_limits<bool>::max()) << std::endl;
    std::cout << std::endl;

	return 0;
}