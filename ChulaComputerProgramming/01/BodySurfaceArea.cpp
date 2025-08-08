#include <iomanip>
#include <iostream>
#include <cmath>

double Mosteller(double H, double W)
{
    return sqrt(H*W)/60.0;
}

double Haycock(double H, double W)
{
    //0.024265 × 𝑊0.5378 × 𝐻0.3964
    return 0.024265 * pow(W,0.5378) * pow(H,0.3964);
}

double Boyd(double H, double W)
{
    // 0.0333 × 𝑊(0.6157−0.0188 log10𝑊) × 𝐻0.3
    return 0.0333 * pow(W,0.6157 - (0.0188 * log10(W))) * pow(H,0.3);
}

int main()
{
    double H, W;
    std::cin >> W >> H;

    std::cout <<  std::setprecision(15)
    << Mosteller(H, W) << '\n'
    << Haycock(H, W) << '\n'
    << Boyd(H, W) << '\n';
}
