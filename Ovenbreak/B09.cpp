#include <iostream>


int main()
{
    int speed, height, weight;
    std::cin >> speed >> height >> weight;
    if (height < 100 || weight > 200) 
    {
        puts("It too weak.");
        return 0;
    }

    if (speed >= 100) 
    {
        puts("It can jump over.");
        return 0;
    }
    puts("It can't jump over.");

}