#include <iostream>
#include <cstdint>
#include <cmath>


int main()
{
    int numRestaurants, exhaustT, exhaustE;
    std::cin >> numRestaurants >> exhaustT >> exhaustE;

    int64_t cashT = 0, cashE = 0;
    int curExT = exhaustT, curExE = exhaustE;
    bool isPosT = true, isPosE = false;
    int curPosNah = 0, curNegNah = 0;
    int longestNah = 0;
    while (numRestaurants--)
    {
        int pos, neg;
        bool visitedPos = false, visitedNeg = false;
        std::cin >> pos >> neg;

        if (isPosT)
        {
            if (pos > 0)
            {
                curExT -= 1;
                cashT += pos;
                visitedPos = true;
            }
        }
        else 
        {
            if (neg > 0)
            {
                curExT -= 1;
                cashT += neg;
                visitedNeg = true;
            }
        }
        
        if (isPosE)
        {
            if (pos > 0)
            {
                curExE -= 1;
                if (cashE ==0) cashE = 1;
                cashE *= pos;
                visitedPos = true;
            }
        }
        else 
        {
            if (neg > 0)
            {
                curExE -= 1;
                if (cashE ==0) cashE = 1;
                cashE *= neg;
                visitedNeg = true;
            }
        }
        
        if (!visitedNeg) curNegNah += 1;
        else 
        {
            longestNah = std::max(longestNah, curNegNah);
            curNegNah = 0;
        }

        if (!visitedPos) curPosNah += 1;
        else 
        {
            longestNah = std::max(longestNah, curPosNah);
            curPosNah = 0;
        }

        if (curExT == 0) 
        {
            isPosT = ! isPosT;
            curExT = exhaustT;
        }

        if (curExE == 0) 
        {
            isPosE = ! isPosE;
            curExE = exhaustE;
        }
    }
    longestNah = std::max(longestNah, curPosNah);
    longestNah = std::max(longestNah, curNegNah);
    printf("%d %d %d\n", (int)(cashT % 10007), (int)(cashE % 10007), longestNah);
}