#include <iostream>

int ohbaby[1000][1000];
int sum[1000][1000];

int n;

bool validIndex(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < n;
}

void construct(int i, int j)
{
    while (validIndex(i, j)) 
    {
        sum[i][j] = ohbaby[i][j];
        if (validIndex(i-1, j-1)) sum[i][j] += sum[i-1][j-1];
        i++; j++;
    }
}

int kadaneIsABitch(int i, int j)
{
    int max = ohbaby[i][j];
    int current = ohbaby[i][j];
    i++; j++;
    
    while (validIndex(i, j)) 
    {
        if (ohbaby[i][j] + current > current && current <= 0) current = ohbaby[i][j];
        else current += ohbaby[i][j];
        max = std::max(current, max);
        i++; j++;
    }
    return max;
}

int main()
{
    std::cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> ohbaby[i][j];
    
    // start with top row
    for (int j = 0; j < n; j++)
    {
        int i = 0;
        construct(i, j);
    }
    
    // then go to left column
    for (int i = 1; i < n; i++) // (0,0) already done
    {
        int j = 0;
        construct(i, j);
    }
    
    int maxxxxx = -1e9 - 1;
    
    // kadane top row
    for (int j = 0; j < n; j++)
    {
        int i = 0;
        maxxxxx = std::max(kadaneIsABitch(i, j), maxxxxx);
    }
    
    // kadane left column
    for (int i = 1; i < n; i++)
    {
        int j = 0;
        maxxxxx = std::max(kadaneIsABitch(i, j), maxxxxx);
    }
    
    for (int i = 0; i < n; i++) {for (int j = 0; j < n; j++) std::cout << sum[i][j] << ' '; std::cout << '\n';}
    
    std::cout << maxxxxx << '\n';
}