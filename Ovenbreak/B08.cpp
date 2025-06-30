#include <iostream>

void printthing(int val)
{
    printf("%d\n", val);
}

int main()
{
    int x, y;
    int z;
    std::cin >> x >> y >> z;

    switch(z)
    {
        case 1:
            printthing(x+y);
            break;
        case 2:
            printthing(x-y);
            break;
        case 3:
            printthing(x*y);
            break;
        case 4:
            if (y == 0) 
            {
                puts("cannot divide by zero");
                return 0;
            }
            printthing(x/y);
            break;
        case 5:
            if (y == 0) 
            {
                puts("cannot divide by zero");
                return 0 ;
            }
            printthing((int)x%(int)y);
            break;
    }
}
