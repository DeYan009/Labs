#include <func.hpp>

// #include <iostream>

int main() 
{
    // ex 1

    // ex 2

    int n;
    std::string words[N_Max];
    Read(n, words);
    for (int i = 0; i < n; i++)
    {
        if (isThreeMoreConsonants(words[i]))
		{
            // std::cout << "YES" << ' ' << words[i] << std::endl;
            DeleteVowels(words[i]);
            // DoubleConsonants(words[i]);
        }
    }
    Write(n, words);
    // ex 3
    
	return 0;
}
