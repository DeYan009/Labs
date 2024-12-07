#include <func.hpp>

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

char toLower(char c)
{
    if('A' <= c && c <= 'Z')
        c += 32;
    return c;
}

char toUpper(char c)
{
    if('a' <= c && c <= 'z')
        c -= 32;
    return c;
}

void Sort(int& n, std::string words[N_Max])
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(words[i] > words[j])
                {
                    std::string tmp = words[i];
                    words[i] = words[j];
                    words[j] = tmp;
                }
}

// std::string toLowerCase(std::string s)
// {
//     for(int i=0;i<s.length();i++)
//     {
//         if('A' <= s[i] && s[i] <= 'Z')
//             s[i] += 32;
//     }
//     return s;
// }
// std::string toLowerCase(const std::string& s)
// {
//     std::string result = s; // Создаем копию входной строки
//     for (int i = 0; i < result.length(); i++) {
//         // Проверяем, является ли символ заглавной буквой
//         if (result[i] >= 'A' && result[i] <= 'Z') {
//             result[i] += 32; // Преобразуем в строчную букву
//         }
//     }
//     return result; // Возвращаем преобразованную строку
// }
std::string toLowerCase(std::string word)
{
    std::string newword = "";
    for(int i=0;i<word.length();i++)
    {
        newword += toLower(word[i]);
    }
    return word;
}

std::string toUpperCase(std::string word)
{
    std::string newword = "";
    for(int i=0;i<word.length();i++)
    {
        newword += toUpper(word[i]);
    }
    return word;
}

bool isVowel(char c)
{
    c = toLower(c);
    std::string vowels = "aeiouy";
    if(vowels.find(toLower(c)) != std::string::npos)
        return true;
    return false;
}

// void DeliteElem(int& n, std::string words[N_Max])
// {
//     int k = 0;
//     for (int i = 0; i < n; i++) {
//         if (!isThreeMoreConsonants(words[i]))
// 		{
//             words[k] = words[i];
//             k++;
//         }
//     }
//     n = k;
// }

bool isLetter(char c)
{
    if(('A' <= c && c <= 'Z') ||
       ('a' <= c && c <= 'z'))
       return true;
    return false;
}

void RemoveOtherSymbols(std::string& word)
{
    for(int i=0;i<word.length();i++)
        if(!isLetter(word[i]))
        {
            word.erase(i, 1);
            i--;
        }          
}

void DeleteVowels(std::string& word)
{
	for(int i=0;i<word.length();i++)
        if(isVowel(word[i]))
            {
                word.erase(i, 1);
                i--;
            }

}

void DoubleConsonants(std::string& word)
{
	for(int i=0;i<word.length();i++)
        if(!isVowel(word[i]))
            {
                word.insert(i+1, 1, word[i]);
                i++;
            }
}

void NewFormat(std::string& word)
{
    std::string dl = "";
    for(int i=0;i<word.length()-1;i++)
    {
        if(word[i] == word[i+1] && isLetter(word[i]))
            {
                dl += word[i];
                i++;
            }
    }
    word = toUpperCase(word) + "(" + dl + ")";
}

bool isThreeMoreConsonants(std::string word)
{
	int cnt = 0;
	for(int i=0;i<word.length();i++)
        if(!isVowel(word[i]))
            cnt++;
    return cnt > 3;
}

bool isDoubleLetter(const std::string word)
{
    bool doubleletter = false;
    for(int i=0;i<word.length()-1;i++)
    {
        if(word[i] == word[i+1] && isLetter(word[i]))
            doubleletter = true;
    }
    return doubleletter;
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