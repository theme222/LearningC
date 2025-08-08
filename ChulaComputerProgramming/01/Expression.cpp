#include <cmath>
#include <iostream>

int fac(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    double bottom = pow(1.2, cbrt(2.3));
    double pi = 3.1415926535;
    double frac = fac(10)/ pow(8,8);
    double wtf = log(9.7);
    double expo = (7.0 / sqrt(71)) - sin(40.0 / 180.0 * pi);
    double totalwtf = pow(wtf, expo);
    double result = (pi - frac + totalwtf) / bottom;
    std::cout << result;
}
