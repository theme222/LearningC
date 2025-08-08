#include <iostream>
#include <cmath>

double root(double a,double b, double c)
{
    return sqrt(b*b - (4 * a * c));
}

double roundddd(double t)
{
    return round(t * 1e3) / 1e3;
}

int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;

    double rooththing = root(a,b,c);
    double x1 = (-b - rooththing) / (2 * a);
    double x2 = (-b + rooththing) / (2 * a);
    std::cout << roundddd(x1) << ' ' << roundddd(x2) << std::endl;
}
