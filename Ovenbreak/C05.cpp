#include <iostream>
#include <cstdint>


int main()
{
    uint64_t total = 0, n, prev = 1;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        prev *= i;
        total += prev;
    }

    printf("%lu\n", total);
}
