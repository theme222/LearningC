#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

std::vector<int> primes;
int matrix[501][501];

bool IsPrime(int num)
{
    int rootNum = ceil(sqrt(num));
    for (int i = 2; i <= rootNum; i++)
        if (num % i == 0) return false;
    return true;
}

int GetNextPrime(int prime)
{
    while (prime++)
        if (IsPrime(prime)) break;
    return prime;
}

int GetNearestPrimeDist(int num) // modified binary search
{
    if (num == 1) return 1;
    int left = 0;
    int right = primes.size()-1;
    while (right - left > 1)
    {
        int center = left + ((right-left)/2);
        // printf("%d %d %d\n", left, right, primes[center]);
        if (num == primes[center]) return 0;
        else if (num < primes[center])
            right = center;
        else
            left = center;
    }
    if (primes[right] == num || primes[left] == num) return 0;
    if (right - left == 1) return primes[right] - num;
    else return 0;
}

int main()
{
    primes.reserve(100000);
    int currentCheck = 2;
    do {
        primes.push_back(currentCheck);
        currentCheck = GetNextPrime(currentCheck);
    } while (currentCheck < 101000);

    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j =0; j < m; j++)
            scanf("%d", matrix[i]+j);

    // for (auto a: primes)
    //     printf("%d\n", a);

    int smallestDist = 2e9;

    // Check rows
    for (int i = 0; i < n; i++)
    {
        int currentSum = 0;
        for (int j = 0; j < m; j++)
            currentSum += GetNearestPrimeDist(matrix[i][j]);
        smallestDist = std::min(smallestDist, currentSum);
    }

    // Check columns
    for (int i = 0; i < m; i++)
    {
        int currentSum = 0;
        for (int j = 0; j < n; j++)
            currentSum += GetNearestPrimeDist(matrix[j][i]);
        smallestDist = std::min(smallestDist, currentSum);
    }
    std::cout << smallestDist << std::endl;
}
