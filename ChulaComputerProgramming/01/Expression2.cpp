#include <iostream>
#include <cmath>

int main()
{
    double x;
    std::cin >> x;
    double top = pow(x, sqrt(log((x+1) * (x+1))));
    double bottom = 10-x;
    std::cout << (round((top/bottom) * 1e6) / 1e6) << std::endl;
}
