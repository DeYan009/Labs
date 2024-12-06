#pragma once
#include <string>

const int N_Max = 5120;

bool Read(int& n, std::string words[N_Max]);
void Sort(int& n, std::string words[N_Max]);
void DeliteElem(int n, std::string words[N_Max]);
bool isThreeMoreConsonants(const std::string word);
void Write(int& n, std::string words[N_Max]);
