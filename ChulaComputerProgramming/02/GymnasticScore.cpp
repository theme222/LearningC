#include <iostream>
#include <cmath>

int main()
{
    double a,b,c,d;
    std::cin >> a >> b >> c >> d;
    double min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    double max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    std::cout << round(100 * ((a + b + c + d - min - max) / 2)) / 100 << std::endl;
}
