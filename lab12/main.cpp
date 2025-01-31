#include <iostream>


int lenstring(std::string s)
{
    if (s != "")
    {
        return 1 + lenstring(s.substr(1));
    }
    return 0;
}

int main() 
{
    // ex 1
    std::string s;
    std::cin >> s;
    std::cout << lenstring(s);
    // std::cout << lenstring("");

    // ex 2
    std::cout << "hello world" << std::endl;
	return 0;
}