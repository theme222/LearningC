#include <iostream>
#include <cmath>

int main()
{
    double min = 1e30, max = 0, avg = 0, in;
    int nums;

    std::cin >> nums;
    for (int i =0 ; i < nums; i++)
    {
        std::cin >> in;
        if (in < min) min = in;
        if (in > max) max = in;
        avg += in;
    }

    avg /= nums;
    printf("%d\n", (int)ceil(min + max + avg));
}
