#include <func.hpp>

// #include <iostream>

int main() 
{
    // // ex 1

    // int n;
    // std::string words[N_Max];
    // std::string newwords[N_Max];
    // int j = 0;
    // if(!Read(n, words))
	// 	return -1;
    // for (int i = 0; i < n; i++)
    // {
    //     RemoveOtherSymbols(words[i]);
    //     if (isConsonantsAlphabet(words[i]))
	// 	{
    //         // std::cout << "YES" << ' ' << words[i] << std::endl;
    //         newwords[j] = words[i];
    //         j++;
    //     }
    // }
    // SortLenght(j, newwords);
    // UnicWords(j, newwords);
    // Write(j, newwords);

    // // ex 2

    // int n;
    // std::string words[N_Max];
    // if(!Read(n, words))
	// 	return -1;
    // for (int i = 0; i < n; i++)
    // {
    //     RemoveOtherSymbols(words[i]);
    //     if (isThreeMoreConsonants(words[i]))
	// 	{
    //         // std::cout << "YES" << ' ' << words[i] << std::endl;
    //         DeleteVowels(words[i]);
    //         DoubleConsonants(words[i]);
    //     }
    // }
    // // Write(n, words);
    // // std::cout << "+++++++++++++++++++" << std::endl;
    // Sort(n, words);
    // Write(n, words);

    // ex 3
    int n;
    std::string words[N_Max];
    if(!Read(n, words))
		return -1;
    for (int i = 0; i < n; i++)
    {
        if (isDoubleLetter(words[i]))
		{
            // std::cout << "YES" << ' ' << words[i] << std::endl;
            NewFormat(words[i]);
        }
    }
    Write(n, words);
    
	return 0;
}
