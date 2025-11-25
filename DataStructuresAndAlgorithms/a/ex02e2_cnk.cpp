#include <iostream>

int memoCNK[31][31]; // n k

int main()
{
    int n, k;
    std::cin >> n >> k;
    
    // init
    for (int i = 0; i <= 30; i++)
    {
        memoCNK[0][i] = 0;
        memoCNK[i][0] = 1;
        memoCNK[i][i] = 1;
    }
    
    // construct
    for (int i = 1; i <= 30; i++)
        for (int j = 1; j <= 30; j++)
            memoCNK[i][j] = memoCNK[i-1][j-1] + memoCNK[i-1][j];
    
    std::cout << memoCNK[n][k] << '\n';
}