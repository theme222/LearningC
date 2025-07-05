#include <iostream>

int main()
{
    int num;
    std::cin >> num;

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            printf("%d", i);
            if (i != num) printf(" ");
        }
    }
    puts("");
}
