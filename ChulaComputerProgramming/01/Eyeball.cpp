#include <iostream>
#include <cmath>


int main()
{
    double xe, ye, re, rp, xm, ym;
    std::cin >> xe >> ye >> re >> rp >> xm >> ym;
    double radius = re - rp;

    double deltax = (int)(xm - xe);
    double deltay = (int)(ym - ym);
    double distToMouse = sqrt((deltax * deltax) + (deltay * deltay));

    double ratio = radius / distToMouse;
    double changeX = deltax * ratio;
    double changeY = deltay * ratio;
    std::cout << (int)round(xe + changeX) << " " << (int)(round(ye + changeY)) << '\n';
}
