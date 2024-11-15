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


    // // ex 1
    // int n;
	// std::cin >> n;
    // int mas[10000];
	// for(int i=0;i<n;i++)
	// {
	// 	mas[i] = i + 1;
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

    // ex 2
	int n;
	std::cin >> n;
    int a[1000];
	int fd[1000];
	int md[1000];
	for(int i=0;i<n;i++)
	{
		int num = i + 1;
		a[i] = num;
		fd[i] = num;
		md[i] = num;
		while(fd[i] > 9) fd[i] /= 10;
		while (num > 0)
		{
        int d = num % 10; // Получаем последнюю цифру
        if (d < md[i])
			{
            	md[i] = d; // Обновляем минимальную цифру
        	}
        num /= 10; // Убираем последнюю цифру
    	}

	}

	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
        if (a[i] < a[j])
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}

	for(int i=0;i<n;i++)
		std::cout << a[i] << std::endl;

    // ex 3

    // ex 4

	return 0;
}
