#include <iostream>

std::string operator*(std::string a, int n)
{
    std::string ret = "";
    while (n--)
        ret += a;
    return ret;
}

int main()
{
    int h;
    std::cin >> h;

    std::cout << std::string(".") * (h-1) << "*\n";

    int startCount = h-2;
    int middle = 1;

    while (startCount > 0)
    {
        std::cout << std::string(".") * (startCount)
            << "*"
            << std::string(".") * middle
            <<"*\n";
        startCount--;
        middle += 2;
    }
    std::cout << std::string("*") * (2*h-1) << '\n';
}
