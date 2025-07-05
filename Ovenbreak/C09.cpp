#include <iostream>
#include <cstdint>

int main()
{
    uint64_t goal;
    std::cin >> goal;

    uint64_t total = 1;
    uint64_t prev = 1, prev2 = 0;
    uint64_t current = 1;
    uint64_t count = 2;

    while (count <= goal)
    {
        count++;
        current = prev + prev2;
        total += current;
        prev2 = prev;
        prev = current;
    }
    std::cout << total << '\n';
}