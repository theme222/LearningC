#include <iostream>

int main()
{
    long n;
    std::cin >> n;

    long currentDivider = 2;

    bool isFirstDiv = true;
    while (n > 1)
    {
        if (n % currentDivider == 0)
        {
            n /= currentDivider;
            if (isFirstDiv) std::cout << currentDivider;
            else  std::cout << '*' << currentDivider;
            isFirstDiv = false;
        }
        else
        {
            currentDivider++;
        }
    }
    puts("");
}
