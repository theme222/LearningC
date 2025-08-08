#include <iostream>

int main()
{
    int weight;
    std::cin >> weight;
    if (weight <= 100) puts("18");
    else if (weight <= 250) puts("22");
    else if (weight <= 500) puts("28");
    else if (weight <= 1000) puts("38");
    else if (weight <= 2000) puts("58");
    else puts("Reject");
}
