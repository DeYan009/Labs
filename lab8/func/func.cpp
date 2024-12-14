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

void SortLenght(int& n, std::string words[N_Max])
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(words[i].length() < words[j].length())
                {
                    std::string tmp = words[i];
                    words[i] = words[j];
                    words[j] = tmp;
                }
}

void UnicWords(int& n, std::string words[N_Max])
{
    int unic_n = 0;
    std::string unicwords[N_Max];
    bool unicFlag;
    for(int i=0;i<n;i++)
    {
        unicFlag = true;
        for(int j=0;j<unic_n;j++)
            if(words[i] == unicwords[j])
                {
                    unicFlag = false;
                    break;
                }
        if(unicFlag)
            {
                unicwords[unic_n] = words[i];
                unic_n++;
            }
    }
    for (int i = 0; i < unic_n; i++)
    {
        words[i] = unicwords[i];
    }
    n = unic_n;
        
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
    return newword;
}

std::string toUpperCase(std::string word)
{
    std::string newword = "";
    for(int i=0;i<word.length();i++)
    {
        newword += toUpper(word[i]);
    }
    return newword;
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

bool isConsonantsAlphabet(std::string word)
{
    DeleteVowels(word);
    if(word == "")
        return false;
    word = toLowerCase(word);
    for(int i=0;i<word.length()-1;i++)
        if(word[i] > word[i+1])
            return false;
    return true;
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
    if(word == " " || word == "\n" || word == "")
        return doubleletter;
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

bool Read3(int& n, std::string words[N_Max])
{
    std::ifstream in("input.txt");
    if(!in.is_open())
    {
        std::cout << "File not opened" << std::endl;
        return false;
    }

    n = 0;
    std::string line;
    std::string word;
    while(!in.eof())
    {
        while(getline(in, line))
        {
            word = "";
            for(int i=0;i<line.length();i++)
            {
                if(isLetter(line[i]))
                    word += line[i];
                else
                {
                    words[n] = word;
                    word = "";
                    n++;
                    words[n] = line[i];
                    n++;
                }
            }
            if(!word.empty())
            {
                words[n] = word;
                word = "";
                n++;
            }
            words[n] = "\n";
            n++;
        }
        
    }

    return true;
}

void Write3(int& n, std::string words[N_Max])
{
	std::ofstream out("output.txt");
    for(int i=0;i<n;i++)
	{
        std::cout << "<" << words[i] << ">" << std::endl;
		out << words[i];
	}

}