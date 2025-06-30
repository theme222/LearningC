#include <iostream>
#include <iomanip>
#include <cmath>

int CalcTotal(int range)
{
    return (4 * range) + (((range - 1)/(double)2) * (range) * 4);
}


int main()
{
    std::string name;
    int min, max;
    std::cin >> name >> min >> max;

    int total = CalcTotal(max) - CalcTotal(min-1);

    printf("%s has %d attackable tiles.\n", name.c_str(), total);
} 
