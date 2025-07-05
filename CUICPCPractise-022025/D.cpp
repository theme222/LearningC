#include <iostream>


int pos[100000], heights[100000];
int main()
{
    int num;
    std::cin >> num;

    for (int i = 0; i < num; i++)
        scanf("%d %d", pos+i, heights+i);

    int tree = 0;
    int leftOccupied = 0, rightOccupied = 0;
    for (int i = 0; i < num; i++)
    {
        if (i == 0)
        {
            tree++;
            continue;
        }
        if (i == num-1)
        {
            tree++;
            continue;
        }

        if (pos[i] - heights[i] > pos[i-1]+leftOccupied)
        {
            tree++;
            leftOccupied = heights[i];
        }
        else if (pos[i] + heights[i] < pos[i+1])
        {
            tree++;
            rightOccupied = heights[i];
        }

        leftOccupied = rightOccupied;
        rightOccupied = 0;
    }

    printf("%d\n", tree);
}
