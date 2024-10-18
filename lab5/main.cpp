#include <iostream>
#include <iomanip>

int main() 
{
    // ex 1
    int Aj;
    int sum_0_or_7 = 0;
    int max_in_sum = INT32_MIN;
    int num_max_in_sum = INT32_MIN;
    std::cin >> Aj;
    for (int j = 1; j <= Aj; j++)
    {
        int a;
        std::cin >> a;
        int lasta = a % 10;
        if (lasta == 0 || lasta == 7)
        {
            sum_0_or_7 += a;
            if (max_in_sum < a)
            {
                max_in_sum = a;
                num_max_in_sum = j;
            }
        }
        
    }
    std::cout << "Sum elem:"<< sum_0_or_7 << " max:" << max_in_sum << "num:" << num_max_in_sum << std::endl;
    // // ex 2
    // int N;
    // int lastn;
    // int summ = 0;
    // std::cin >> N;
    // while (N > 0)
    // {
    //     lastn = N % 10;
    //     if (lastn % 2 != 0)
    //     {
    //         summ += lastn;
    //     }

    //     N /= 10;
    // }
    // std::cout << summ << std::endl;

	return 0;
}