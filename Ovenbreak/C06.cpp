#include <iostream>
#include <cmath>

int main()
{
    int types;
    std::cin >> types;

    double total = 0;
    int totalCount = 0;

    for (int i = 0; i < types; i++)
    {
        int count, price;
        std::cin >> count >> price;

        total += count * price;
        totalCount += count;
    }


    if (totalCount >= 2 * types)
    {
        total *= 0.97;
        if (totalCount > 14 && total > 25)
            total -= 10;
    }
    else if (totalCount < 20 && total < 500)
        total += 600;
    else
    {
        total *= 0.65;
    }

    printf("%d\n", (int)total);
}
