#include <iostream>

int main()
{
    int temp;
    std::cin >> temp;
    puts(temp > 180 ? "Burnt": (temp >= 160) ? "Perfect": "Undercooked");
}