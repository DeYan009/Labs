#pragma once
#include <string>
#include <iostream>

const int N_Max = 5120;

bool Read(int& n, std::string words[N_Max]);
void RemoveOtherSymbols(std::string& word);
void Sort(int& n, std::string words[N_Max]);
void SortLenght(int& n, std::string words[N_Max]);
void UnicWords(int& n, std::string words[N_Max]);
// void DeliteElem(int n, std::string words[N_Max]);
void DeleteVowels(std::string& word);
void DoubleConsonants(std::string& word);
void NewFormat(std::string& word);
bool isConsonantsAlphabet(std::string word);
bool isThreeMoreConsonants(const std::string word);
bool isDoubleLetter(const std::string word);
void Write(int& n, std::string words[N_Max]);
bool Read3(int& n, std::string words[N_Max]);
void Write3(int& n, std::string words[N_Max]);