#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
    std::string sss;
    std::cin >> sss;
    double a = std::stod(sss);
    double L = 0, R = a;

    double val = pow(10,(R-L)/2);
    while (fabs(val - a) > (pow(10, -10) * std::max(val,a)))
    {
        if (val > a)
        {
            R = (R - L) / 2.0 + L;
        }
        else
        {
            L = (R - L) / 2.0 + L;
        }
        val = pow(10.0,(R-L)/2.0 + L);
    }
    std::cout << (R-L)/2.0+L << '\n';
}
