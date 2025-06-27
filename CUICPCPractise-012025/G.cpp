#include <iostream>

char min[100], max[100];
int main()
{
    int length, goal;
    std::cin >> length >> goal;

    for (int i = 0; i < length; i++)
    {
        min[i] = '0';
        max[i] = '0';
    }

    // find min
    int minGoal = goal;
    for (int minIndex = length-1; minIndex >= 0; minIndex--)
    {
        if (minGoal - 9 < 0)
        {
            min[minIndex] = '0' + minGoal;
            minGoal = 0;
            break;
        }

        minGoal -= 9;
        min[minIndex] = '9';
    }

    if (min[0] == '0') {
        for (int i = 1; i < length; i++)
        {
            if (min[i] != '0')
            {
                min[i] -= 1;
                min[0] = '1';
                break;
            }
        }
    }

    // find max
    int maxGoal = goal;
    for (int i = 0; i < length; i++)
    {
        if (maxGoal - 9 < 0)
        {
            max[i] = '0' + maxGoal;
            maxGoal = 0;
            break;
        }

        maxGoal -= 9;
        max[i] = '9';
    }

    printf("%s %s\n",
        minGoal != 0 || (min[0] == '0' && length > 1) ? "-1" : min,
        maxGoal != 0 || (max[0] == '0' && length > 1) ? "-1" : max);
}
