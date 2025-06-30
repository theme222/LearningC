#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

double ln(int num)
{
    return log(num) / log(M_E);
}

int main()
{
    int C, M, L;
    std::cin >> C >> M >> L;
    double power = ceil(((double)(C*C) + ln(M + 1)) * pow(M_E, (double)L/(double)(C+1)));
    printf("%.2f\n", power);
}