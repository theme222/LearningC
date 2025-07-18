#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353lu
typedef long long ll;
typedef unsigned long long llu;

llu numbers[200001];
llu sortedNumbers[200001];
bool isAKHighestNum[200001];
int main()
{
    ll n, k;
    std::cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        llu num;
        scanf("%llu", &num);
        numbers[i] = num;
        sortedNumbers[i] = num;
    }

    std::sort(sortedNumbers, sortedNumbers+n);

    llu maxPartitionValue = 0;
    for (int i = n-1; i > n-1-k; i--)
    {
        isAKHighestNum[sortedNumbers[i]] = true;
        maxPartitionValue += sortedNumbers[i];
    }

    llu totalPossibilities = 1;
    int lastIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (isAKHighestNum[numbers[i]])
        {
            // std::cout << numbers[i] << std::endl;
            if (lastIndex == -1)
            {
                lastIndex = i;
                continue;
            }
            totalPossibilities *= i - lastIndex;
            totalPossibilities %= MOD;
            lastIndex = i;
        }
    }

    std::cout << maxPartitionValue << ' ' << totalPossibilities % MOD << std::endl;
    // for (auto a: kHighestNums)
    // {
    //     std::cout << a << std::endl;
    // }
}
