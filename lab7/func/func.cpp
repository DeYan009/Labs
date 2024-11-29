#include <func.hpp>
#include <iostream>

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
	return;
}

bool isPrime(int x)
{
	if(x < 2)
		return false;
	for(int d = 2; d <= sqrt(x); d++)
		if(x % d == 0)
			return false;
	return true;
}

void Read(int mas[N_Max][N_Max], int& n)
{
	std::cin >> n;
	for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
		    std::cin >> mas[i][j];
}

void Write(int mas[N_Max][N_Max], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		    std::cout << mas[i][j] << " ";
		std::cout << std::endl;
	}
}

// void Sort(int mas[N_Max][N_Max], int n)
// {
// 	for(int i=0;i<n-1;i++)
// 		for(int j = i + 1; j<n;j++)
// 			if(mas[i] > mas[j])
// 				swap(mas[i], mas[j]);
// }