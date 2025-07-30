#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cmath>

bool IsPrime(uint64_t num)
{
    uint64_t rootedNum = (uint64_t)ceil(sqrt(num));
    for (int i = 2; i <= num; i++)
        if (num%i == 0) return false;
    return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        uint64_t numbers[301];
        for (int i = 0; i < n; i++) scanf("%lu", numbers+i);
        std::sort(numbers, numbers+n);
        
        bool isValid = false;
        for (int i = 0; i < n; i++)
        {
            if (IsPrime(numbers[i])) continue;
            for (int j = 0; j < i; j++)
            {
                if (numbers[i] % numbers[j] == 0) isValid = true;
            }
        }

        if (!isValid) 
        {
            printf("%d\n",-1);
            continue;
        }

        uint64_t full = numbers[0] * numbers[n-1];
        // printf("%lu\n",full);
        for (int i = 0; i <= n/2; i++)
        {
            if (full % numbers[i] != 0) 
            {
                printf("%d\n",-1);
                break;
            }
            if (i == n/2) 
            {
                std::cout << full << '\n';
                break;
            }
        }
    }

}