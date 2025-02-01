#include <iostream>
#include <fstream>
#pragma comment(linker, "/STACK:16777216")

int lenstring(std::string s)
{
    if (s != "")
    {
        return 1 + lenstring(s.substr(1));
    }
    return 0;
}

void SwapSort(int n, int* arr)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(arr[i] > arr[j])
                {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
}

void QuickSort(int a, int b, int* arr)
{
    if(a>=b)
        return;
    int k = (rand()*rand()) % (b-a+1) + a;
    int m = arr[k];

    int l = a - 1;
    int r = b + 1;
    while(true) {
        do l++; while(arr[l] < m);
        do r--; while(arr[r] > m);
        if(l >= r) 
            break;
        std::swap(arr[l], arr[r]);
    }
    l = r;
    r++;
    QuickSort(a, l, arr);
    QuickSort(r, b, arr);
}

void Search(int i, int j, int step, int n, int m, char field[100][100], int table[100][100])
{
    if(step >= table[i][j])
        return;

    table[i][j] = step;

    if(field[i][j] == 'E')
        return;

    if(i + 1 < n && field[i+1][j] != '#')
        Search(i+1,j,step+1,n,m,field,table);
    if(i - 1 >= 0 && field[i-1][j] != '#')
        Search(i-1,j,step+1,n,m,field,table);
    if(j + 1 < m && field[i][j + 1] != '#')
        Search(i,j+1,step+1,n,m,field,table);
    if(j - 1 >= 0 && field[i][j - 1] != '#')
        Search(i,j-1,step+1,n,m,field,table);
    
    if(i + 1 < n && j + 1 < m && field[i+1][j+1] != '#')
        Search(i+1,j,step+1,n,m,field,table);
    if(i - 1 >= 0 && j - 1 >= 0 && field[i-1][j-1] != '#')
        Search(i-1,j,step+1,n,m,field,table);
    if(i - 1 >= 0 && j + 1 < m && field[i-1][j + 1] != '#')
        Search(i,j+1,step+1,n,m,field,table);
    if(i + 1 < n && j - 1 >= 0 && field[i+1][j - 1] != '#')
        Search(i,j-1,step+1,n,m,field,table);
    
}

int main() 
{
    // // ex 1
    // std::string s;
    // std::cin >> s;
    // std::cout << lenstring(s);
    // // std::cout << lenstring("");

    // // ex 2
    // srand(time(0));
    // const int n = 1'000'000;
    // int s[n] = {1, 2, 4 , 8, 7, 4};
    // QuickSort(0, n-1, s);
    // // SwapSort(n, s);
    // for(int i=0;i<n;i++)
    //     std::cout << s[i];

    // ex 3
    char field[100][100];
    int table[100][100];

    std::ifstream in("input.txt");
    int n, m;
    int is, js;
    int ie, je;
    in >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            table[i][j] = INT_MAX;
            in >> field[i][j];
            if(field[i][j] == 'S') {
                is = i;
                js = j;
            }
            else if(field[i][j] == 'E') {
                ie = i;
                je = j;
            }
        }

    Search(is, js, 0, n, m, field, table);
    std::cout << table[ie][je] << std::endl;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            std::cout << field[i][j] << ' ';
        std::cout << std::endl;
    }
	// return 0;
}