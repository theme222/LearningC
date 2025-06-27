#include <iostream>

int soldierHeights[105];
int main()
{
    int soldiers, time = 0, max = -1, min = 1e9;
    std::cin >> soldiers;
    for (int i = 0; i < soldiers; i++)
    {
        std::cin >> soldierHeights[i];
        if (soldierHeights[i] > max) max = soldierHeights[i];
        if (soldierHeights[i] < min) min = soldierHeights[i];
    }

    for (int i = 0; i < soldiers; i++)
    {
        if (soldierHeights[i] == max)
        {
            time += i;
            break;
        }
    }

    for (int i = soldiers -1; i >= 0; i--)
    {
        if (soldierHeights[i] == min)
        {
            time += soldiers-1-i - (time > i ? 1 : 0);
            break;
        }
    }
    printf("%d\n", time);
}
