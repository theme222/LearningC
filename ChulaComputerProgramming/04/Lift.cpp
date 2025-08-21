#include <iostream>
#include <cmath>

int liftFrom[100];
int liftTo[100];

bool ComesBefore(int lift, int person, bool isGoingUp)
{
    return isGoingUp ? lift <= person : lift >= person;
}

int CalculateWeight(int from, int to, int liftIndex)
{
    // Check same direction
    int lFrom = liftFrom[liftIndex];
    int lTo = liftTo[liftIndex];

    bool liftGoingUp = to - from > 0;
    bool personGoingUp = lTo - lFrom > 0;

    if (liftGoingUp == personGoingUp && ComesBefore(lFrom, from, liftGoingUp)) // same direction
        return abs(lTo - to);
    else // Case lift coming before when going same direction and case lift going opposite directions all fall to this statement
        return abs(lTo - from) + abs(from - to);
}

int main()
{
    int liftCount;
    std::cin >> liftCount;

    // Input
    for (int i = 1; i <= liftCount; i++)
    {
        int num, from, to;
        std::cin >> num >> from >> to;

        liftFrom[num] = from;
        liftTo[num] = to;
    }

    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        int from, to;
        std::cin >> from >> to;

        int lowestWeight = CalculateWeight(from, to, 1);
        int lowestIndex = 1;
        for (int i = 2; i <= liftCount; i++)
        {
            if (lowestWeight > CalculateWeight(from, to, i))
            {
                lowestIndex = i;
                lowestWeight = CalculateWeight(from, to, i);
            }
        }
        printf(">> %d\n", lowestIndex);
    }
}
