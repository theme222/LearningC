#include <iostream>
#include <cmath>
#include <cstdint>

int main()
{
    char unit;
    double target, real;

    std::cin >> target >> unit;
    std::cin >> real;

    switch(unit)
    {
        case 'g':
            target = target;
            break;
        case 'k':
            target *= 1000;
            break;
        case 't':
            target *= 1000000;
            break;
    }

    if (target == real) puts("Perfect");
    else 
    {
        double thing = fabs((((double)target / (double)real) - 1) * 100);
        if (thing <= 5) puts("Pretty Good");
        else
        {
            if (target > real) puts("Add More");
            else puts("Too Much");
        }
    }



}