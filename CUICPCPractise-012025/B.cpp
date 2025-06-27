#include <iostream>
#include <cstdint>
#include <cmath>

bool IsPrime(uint64_t num)
{
    if (num == 1) return false;
    uint64_t rootedNum = sqrt(num) + 1;
    for (int i = 2; i < rootedNum; i++)
        if (num % i == 0) return false;
    return true;
}

int main()
{
    uint32_t numCount;
    std::cin >> numCount;

    while (numCount--)
    {
        uint64_t number;
        scanf("%I64d", &number);
        if (number == 1)
        {
            puts("NO");
            continue;
        }
        double rootedNum = (double)sqrt(number);
        puts(rootedNum == (uint64_t)rootedNum && IsPrime(rootedNum) ? "YES" : "NO");
    }
}
