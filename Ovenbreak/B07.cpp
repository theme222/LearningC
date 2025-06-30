#include <iostream>
#include <cmath>

// Odd level can go up at pos 0

int GetLevelAtPos(int pos)
{
    int i = 1;
    while (pow(i, 2) < pos)
    {
        i++;
    }
    return i;
}

int GetCenterAtLevel(int level)
{
    return pow(level, 2) - ((2*(level-1))/2);
}

int GetRel(int pos)
{
    int level = GetLevelAtPos(pos);
    int center = GetCenterAtLevel(level);
    return pos - center;
}

bool PosCanGoUp(int pos)
{
    int level = GetLevelAtPos(pos);
    int center = GetCenterAtLevel(level);
    if (level % 2 == 1) return abs(pos - center) % 2 != 0;
    else return abs(pos - center) % 2 == 0;
}

int GetUpPos(int pos)
{
    int level = GetLevelAtPos(pos);
    int rel = GetRel(pos);
    return GetCenterAtLevel(level-1) + rel;
}

int main()
{
    int start, finish;
    std::cin >> start >> finish;

    int relStart, relFinish, levelStart, levelFinish;
    levelStart = GetLevelAtPos(start);
    levelFinish = GetLevelAtPos(finish);

    relStart = GetRel(start);
    relFinish = GetRel(finish);

    // for (int i = 5; i < 20; i++)
    // {
    //     std::cout << i << GetUpPos(i) << std::endl;
    // }

    int currentPos = start, currentLevel = levelStart;
    int count = 0;
    while (currentPos != finish || currentLevel != levelFinish) 
    {
        if (count > 20) return 0;
        // printf("%d %d \n", currentPos, currentLevel);
        count++;
        int currentRel = GetRel(currentPos);
        if (levelFinish < currentLevel && PosCanGoUp(currentPos)) 
        {
            currentLevel--;
            currentPos = GetUpPos(currentPos); 
        }
        else if (currentRel == relFinish)
        {
            if (currentRel > 0) currentPos--;
            else currentPos++;
        }
        else if (currentRel > relFinish)
        {
            currentPos--;
        }
        else 
        {
            currentPos++;
        }
    }
    std::cout << count << std::endl;
}
