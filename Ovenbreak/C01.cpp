#include <iostream>

int main()
{
    int floors;
    std::cin >> floors;
    for (int i = 1; i <= floors; i++)
    {
        for (int j = 0; j < i; j++)
            printf("*");
        puts("");
    }
}
