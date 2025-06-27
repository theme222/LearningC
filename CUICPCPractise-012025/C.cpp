#include <algorithm>
#include <iostream>
#include <cmath>

int main()
{
    int boys[100], girls[100];
    int boyCount, girlCount, pairs = 0;

    std::cin >> boyCount;
    for (int i = 0; i < boyCount; i++)
        std::cin >> boys[i];


    std::cin >> girlCount;
    for (int i = 0; i < girlCount; i++)
        std::cin >> girls[i];

    std::sort(boys, boys + boyCount);
    std::sort(girls, girls + girlCount);

    for (int boy = 0; boy < boyCount; boy++)
    {
        for (int girl = 0; girl < girlCount; girl++)
        {
            if (girls[girl] == -1) continue;
            if (abs(boys[boy] - girls[girl]) > 1) continue;
            pairs++;
            girls[girl] = -1;
            break;
        }
    }
    printf("%d\n", pairs);
}
