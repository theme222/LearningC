#include <iostream>
#include <cstdint>
#include <cmath>

bool IsPrime(int n)
{
    double goal = ceil(sqrt(n)) + 1;
    switch(n)
    {
        case 0: return false;
        case 1: return false;
        case 2: return true;
    }

    for (int i = 2; i < goal; i++)
    {
        if (n % i == 0 && i != (int)goal) return false;
    }
    return true;
}



int main()
{
    int num, total = 0;
    std::cin >> num;

    while (num > 1)
    {
        int i;
        for (i = 2; i <= num; i++)
        {
            if (num % i == 0 && IsPrime(i)) break;
        }
        num /= i;
        total += i;
    }

    std::cout << total << std::endl;

}