#include <bits/stdc++.h>

int main()
{
    int h1, m1, h2, m2;
    std::cin >> h1 >> m1;
    std::cin >> h2 >> m2;

    int totalMinutes1 = h1 * 60 + m1;
    int totalMinutes2 = h2 * 60 + m2;

    int result = 0;
    if (totalMinutes1 > totalMinutes2) 
    {
        result = 1440 - totalMinutes1 + totalMinutes2; 
    }
    else
    {
        result = totalMinutes2 - totalMinutes1;
    } 

    printf("%d hr %d min until alarm rings.\n", result / 60, result % 60);

}