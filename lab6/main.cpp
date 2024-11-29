#include <iostream>
#include <iomanip>


int main() 
{
    // // ex 1

    // int n;
	// std::cin >> n;
    // int mas[10000];
	// bool prime = false;
	// bool is_prime = true;
	// for(int i=0;i<n;i++)
	// {
	// 	std::cin >> mas[i];
	// 	is_prime = true;
	// 	if (!prime)
	// 		{
	// 			if (mas[i] == 1)
	// 				continue;
	// 			for(int j=2;j*j<=mas[i];j++)
	// 			{
	// 				if (mas[i] % j == 0)
	// 					{
	// 						is_prime = false;
	// 						break;
	// 					}
	// 			if (is_prime)
	// 			{
	// 				prime = true;
	// 			}
	// 			}
	// 		}

	// }
	// if (!prime)
	// 	{
	// 		for(int i=0;i<n-1;i++)
	// 			for(int j=i+1;j<n;j++)
	// 		{
    //     		if (mas[i] < mas[j])
	// 			{
	// 				int tmp = mas[i];
	// 				mas[i] = mas[j];
	// 				mas[j] = tmp;
	// 			}
	// 		}
	// 	}

	// for(int i=0;i<n;i++)
	// 	std::cout << mas[i] << std::endl;

    // // ex 2

	// int n;
	// std::cin >> n;
    // int a[1000];
	// int fd[1000];
	// int md[1000];
	// for(int i=0;i<n;i++)
	// {
	// 	int num;
	// 	std::cin >> num;
	// 	a[i] = num;
	// 	fd[i] = num;
	// 	md[i] = num;
	// 	while(fd[i] > 9) fd[i] /= 10;
	// 	while (num > 0)
	// 	{
    //     int d = num % 10;
    //     if (d < md[i])
	// 		{
    //         	md[i] = d;
    //     	}
    //     num /= 10;
    // 	}

	// }

	// for(int i=0;i<n-1;i++)
	// 	for(int j=i+1;j<n;j++)
	// 	{
    //     if (fd[i] > fd[j])
	// 		{
	// 			int tmp = a[i];
	// 			a[i] = a[j];
	// 			a[j] = tmp;

	// 			tmp = fd[i];
	// 			fd[i] = fd[j];
	// 			fd[j] = tmp;

	// 			tmp = md[i];
	// 			md[i] = md[j];
	// 			md[j] = tmp;

	// 		}
	// 	else if (md[i] > md[j] && fd[i] == fd[j])
	// 		{
	// 			int tmp = a[i];
	// 			a[i] = a[j];
	// 			a[j] = tmp;

	// 			tmp = fd[i];
	// 			fd[i] = fd[j];
	// 			fd[j] = tmp;

	// 			tmp = md[i];
	// 			md[i] = md[j];
	// 			md[j] = tmp;
	// 		}
	// 	else if (md[i] == md[j] && fd[i] == fd[j] && a[i] > a[j])
	// 		{
	// 			int tmp = a[i];
	// 			a[i] = a[j];
	// 			a[j] = tmp;

	// 			tmp = fd[i];
	// 			fd[i] = fd[j];
	// 			fd[j] = tmp;

	// 			tmp = md[i];
	// 			md[i] = md[j];
	// 			md[j] = tmp;
	// 		}
	// 	}

	// for(int i=0;i<n;i++)
	// 	std::cout << a[i] << std::endl;

    // // ex 3

	// int a[100][100];
	// int n,m;
	// int s;
	// int maxs=INT32_MIN;
	// int imax;
	// std::cin >> n >> m;
	// for(int i=0;i<n;i++)
	// {	s = 0;
	// 	for(int j=0;j<m;j++)
	// 	{
	// 		std::cin >> a[i][j];
	// 		s += a[i][j];
	// 	}
	// 	if (s > maxs)
	// 		{
	// 			maxs = s;
	// 			imax = i;
	// 		}

	// }

	// for(int i=0;i<n;i++)
	// {
	// 	if (i != imax)
	// 	{
	// 		for(int j=0;j<m;j++)
	// 			std::cout << a[i][j] << " ";
	// 	}
	// 	else
	// 	{
	// 		for(int j=0;j<m;j++)
	// 		{	
	// 			a[i][j] = maxs;
	// 			std::cout << a[i][j] << " ";
	// 		}
	// 	}
	// 	std::cout << std::endl;
	// }
	// // for(int i=0;i<n;i++)
	// // {
	// // 	for(int j=0;j<m;j++)
	// // 		std::cout << a[i][j] << " ";
	// // 	std::cout << std::endl;
	// // }
    // ex 4

	int n;
	std::cin >> n;
    int a[10000];
	for(int i=0;i<n;i++)
	{
		std::cin >> a[i];
	}

	int j = 0;
	for(int i=0;i<n;i++)
	{
		int num = a[i];
		int rev_num = 0;
		int d;
		while (num > 0)
		{
        	d = num % 10;
        	rev_num = rev_num * 10 + d;
        	num /= 10;
		}
		if(a[i] == rev_num)
		{
			continue;
		}
		a[j] = a[i];
		j++;
	}
	n = j;

	for(int i=0;i<n;i++)
	{
		bool prime = true;
		if (a[i] < 3)
			prime = false;
		for(int j=2;j*j<=a[i];j++)
		{
			if (a[i] % j == 0)
			{
				prime = false;
				break;
			}
		}
		if(prime)
		{
			for(int j=n;j>i;j--)
			{
				a[j] = a[j-1];
			}
			i++;
			n++;
		}
	}

	for(int i=0;i<n;i++)
		std::cout << a[i] << std::endl;


	return 0;

}
