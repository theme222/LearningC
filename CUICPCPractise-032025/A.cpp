#include <iostream>

int main()
{
    int num;
    std::cin >> num;

    int total = num / 2;
    printf("%d\n", total);
    for (int i = 0; i < total-1; i++)
        printf("%d ", 2);
    puts(num%2==0? "2" : "3");
}
