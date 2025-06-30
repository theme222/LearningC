#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double u, a, s;
    std::cin >> s >> u >> a;
    std::cout << round(sqrt(pow(u, 2) + (2 * a * s)) * 100) / 100 << std::setprecision(2) << std::endl;
    return 0;
} 
