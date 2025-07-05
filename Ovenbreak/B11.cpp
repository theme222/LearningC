#include <iostream>

void printLeap()
{
    puts("leap year");
    exit(0);
}

void printNotLeap()
{
    puts("not leap year");
    exit(0);
}

void printNegYear()
{
    puts("year cannot be negative");
    exit(0);
}

int main()
{
    int year;
    std::cin >> year;

    if (year < 0) printNegYear();
    if (year % 4 != 0) printNotLeap();
    if (year % 400 == 0) printLeap();
    if (year % 100 == 0) printNotLeap();
    printLeap();
}
