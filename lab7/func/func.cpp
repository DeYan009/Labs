#include <func.hpp>
#include <iostream>

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
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

bool isHaveTwoMinElements(int mas[N_Max][N_Max], int n)
{
	int minElement = INT32_MAX;
	int countMinElements;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mas[i][j] < minElement)
			{
				minElement = mas[i][j];
				countMinElements = 1;
			}
			else if(mas[i][j] == minElement)
			{
				countMinElements++;
			}
		}
	}
	if(countMinElements == 2)
		return true;
	return false;
}

bool isPrimeAbs(int mas[N_Max][N_Max], int n)
{
	int countPrime = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(isPrime(abs(mas[i][j])))
			{
				countPrime++;
			}
		}
	}
	if(countPrime >= 2)
		return true;
	return false;
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

void Sort(int mas[N_Max][N_Max], int n)
{
	int products[N_Max];

    for (int i=0;i<n;i++)
	{
        products[i] = 1;
        for (int j=0; j<n; j++)
		{
            products[i] *= mas[i][j];
        }
    }

    for (int i=0;i<n-1;i++)
	{
        for (int j=0;j<n-i-1;j++)
		{
            if (products[j] < products[j + 1])
			{
                swap(products[j], products[j + 1]);
                for (int k=0;k<n;k++)
				{
                    swap(mas[j][k], mas[j + 1][k]);
                }
            }
        }
    }
}
