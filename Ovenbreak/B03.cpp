#include <iostream>

int main()
{
    int a;
    std::cin >> a;

    if (a >= 85) puts("A");
    else if (a >= 80) puts("B+");
    else if (a >= 75) puts("B");
    else if (a >= 70) puts("C+");
    else if (a >= 65) puts("C");
    else if (a >= 60) puts("D+");
    else if (a >= 50) puts("D");
    else puts("F");
}