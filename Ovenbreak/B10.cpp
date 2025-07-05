#include <iostream>
#include <iomanip>
#include <cmath>

void out(double a, double percent)
{
    std::cout << (int)ceil(a * percent / 100) << std::endl;
}

int main()
{
    double a;
    std::cin >> a;

    if (a >= 4e6 + 1)
        out(a, 30);
    else if (a >= 2e6+1)
        out(a, 25);
    else if (a >= 1e6+1)
        out(a, 20);
    else if (a >= 5e5+1)
        out(a, 15);
    else if (a >= 3e5+1)
        out(a, 10);
    else if (a >= 150001)
        out(a, 5);
    else
        out(a, 0);
}
