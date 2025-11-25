#include <iostream>

int memo[500];

int topDownFib(int n) // because I am special
{
    if (memo[n] != 0) return memo[n];
    if (n <= 1) return memo[n];
    int val = topDownFib(n-1) + topDownFib(n-2);
    memo[n] = val;
    return val;
}

int main()
{
    int n;
    std::cin >> n;
    
    memo[0] = 0;
    memo[1] = 1;
    std::cout << topDownFib(n) << '\n';
}