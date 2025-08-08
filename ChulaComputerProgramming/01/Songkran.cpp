#include <iostream>

int main()
{
    int year;
    std::cin >> year;
    year -= 543;

    int y = year % 100;
    std::cout << (y + (y/4) + 11) % 7 << std::endl;
}
