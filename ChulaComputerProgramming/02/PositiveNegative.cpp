#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    if (num > 0) puts("positive");
    else if (num < 0) puts("negative");
    else puts("zero");
    puts(num % 2 == 0 ? "even": "odd");
}
