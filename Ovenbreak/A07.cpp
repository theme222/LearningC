#include <iostream>
#include <iomanip>
#include <cmath>

double CustomLog(double val, double base)
{
    return log(val) / log(base);
}

namespace Const
{
    const double PI = 3.14159;
    const double E = 2.71828;
    const double P = 3.28;
    const double S = 1.15112;
    const double N = 4.80852;
    const double D = 69;
    const double L0 = 13.0725;
}


double M[2][2];
double p[2];
double MPResult[2];

double FindLengthMP()
{
    return sqrt(pow(MPResult[0], 2) + pow(MPResult[1], 2));
}

void MultMP()
{
    MPResult[0] = (M[0][0] * p[0]) + (M[0][1] * p[1]);
    MPResult[1] = (M[1][0] * p[0]) + (M[1][1] * p[1]);
}

void SetM(double a)
{
    a = a * (Const::PI / 180.0);
    M[0][0] = cos(a);
    M[0][1] = -sin(a);
    M[1][0] = sin(a);
    M[1][1] = 1;
}

int main()
{
    double I, V, L, H;
    double O, px, py, d;
    std::cin >> I >> V >> L >> H;
    // scanf("%f %f %f %f", &O, &px, &py, &d);
    std::cin >> O >> px >> py >> d; // INPUT IS INCORRECT SOMEHOW????

    // std::cout << I << V << L << H << std::endl;
    // std::cout << O << px << py << d << std::endl;
    // std::cout << O << px << py << std::setprecision(2) << d << std::endl;

    SetM(O);

    // Set p
    p[0] = px;
    p[1] = py;

    MultMP();

    double length = FindLengthMP();
    double topHalf = tan((length / Const::L0) * Const::P) * I * V;

    double bottomHalf = (double)((int)ceil(exp(Const::N * d)) % (int)Const::D) * pow(H, (double)1/(double)3) * L;
    double bigBoi = fabs(cbrt(topHalf / bottomHalf));
    double A = Const::P * CustomLog(bigBoi, Const::S);
    double rounded = round(A * 1e4) / 10000;
    std::cout << rounded << std::setprecision(4) <<  " NP" << std::endl;
} 