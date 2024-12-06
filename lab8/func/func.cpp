#include <func.hpp>
#include <iostream>
#include <fstream>

bool Read(int& n, std::string words[N_Max])
{
    std::ifstream in("input.txt");
    if(!in.is_open())
    {
        std::cout << "File not opened" << std::endl;
        return false;
    }

    n = 0;
    while(!in.eof())
    {
        in >> words[n];
        n++;
    }

    return true;
}

// void Sort(int n, std::string words[N_Max])
// {
//     for(int i=0;i<n-1;i++)
//         for(int j=i+1;j<n;j++)
//             if(toLowerCase(words[i]) < toLowerCase(words[j]))
//                 std::swap(words[i], words[j]);
// }

std::string toLowerCase(std::string s)
{
    for(int i=0;i<s.length();i++)
    {
        if('A' <= s[i] && s[i] <= 'Z')
            s[i] += 32;
    }
    return s;
}

char toLower(char c)
{
    if('A' <= c && c <= 'Z')
        c += 32;
    return c;
}

bool isVowel(char c)
{
    c = toLower(c);
    std::string vowels = "aeiouy";
    if(vowels.find(toLower(c)) != std::string::npos)
        return true;
    return false;
}

void DeliteElem(int& n, std::string words[N_Max])
{
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (!isThreeMoreConsonants(words[i]))
		{
            words[k] = words[i];
            k++;
        }
    }
    n = k;
}

bool isThreeMoreConsonants(const std::string word)
{
	int cnt = 0;
	for(int i=0;i<word.length();i++)
        if(!isVowel(word[i]))
            cnt++;
    return cnt > 3;
}

void Write(int& n, std::string words[N_Max])
{
	std::ofstream out("output.txt");
    for(int i=0;i<n;i++)
	{
        std::cout << "<" << words[i] << ">" << std::endl;
		out << words[i] << std::endl;
	}

}