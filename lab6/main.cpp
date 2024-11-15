#include <iostream>
#include <iomanip>


int main() 
{
	// int n;
	// std::cin >> n;
    // int mas[10000];
	// for(int i=0;i<n;i++)
	// {
	// 	std::cin >> mas[i];
	// }

	// for(int i=0;i<n-1;i++)
	// 	for(int j=i+1;j<n;j++)
	// 	{
    //     if (mas[i] < mas[j])
	// 		{
	// 			int tmp = mas[i];
	// 			mas[i] = mas[j];
	// 			mas[j] = tmp;
	// 		}
	// 	}

	// for(int i=0;i<n;i++)
	// 	std::cout << mas[i] << std::endl;
    // ex 1
    int n;
	std::cin >> n;
    int mas[10000];
	for(int i=0;i<n;i++)
	{
		mas[i] = i + 1;
	}

	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
        if (mas[i] < mas[j])
			{
				int tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;
			}
		}

	for(int i=0;i<n;i++)
		std::cout << mas[i] << std::endl;

    // ex 2

    // ex 3

    // ex 4

	return 0;
}
