#include <iostream>
#include <iomanip>
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

    std::cout << std::fixed << std::setprecision(2) << (int)max << '\n' << (int)min << '\n' << avg << '\n';
}
