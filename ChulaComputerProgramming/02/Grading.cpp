#include <iostream>

int main()
{
    double val;
    std::cin >> val;

    if (val >= 80) puts("A");
    else if (val >= 70) puts("B");
    else if (val >= 60) puts("C");
    else if (val >= 50) puts("D");
    else puts("F");
}
