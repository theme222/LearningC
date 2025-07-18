#include <iostream>
#include <queue>
#include <vector>

using pair = std::pair<int, int>;
#define NULLPAIR pair(-1,-1)

int plane[1001][1001];
// std::vector<bool> inhabitX(1001);
// std::vector<bool> inhabitY(1001);

pair HasNeighbors(int x, int y, int val) // Returns the first coordinate that is equal to val
{
    // Check x axis
    for (int i = 0; i < 1001; i++)
    {
        if (i == x) continue;
        if (plane[i][y] == val) return pair(i,y);
    }

    // Check y axis
    for (int i = 0; i < 1001; i++)
    {
        if (i == y) continue;
        if (plane[x][i] == val) return pair(x,i);
    }
    return NULLPAIR;
}

void ApplyNeighbors(int x, int y, std::queue<pair> &queue)
{
    queue.push(pair(x,y));
    while (!queue.empty())
    {
        pair current = queue.front();
        // inhabitX[current.first] = true;
        // inhabitY[current.second] = true;
        pair nextPair;
        do {
            nextPair = HasNeighbors(current.first, current.second, -1);
            if (nextPair != NULLPAIR)
            {
                plane[nextPair.first][nextPair.second] = -2;
                queue.push(nextPair);
            }
        } while(nextPair != NULLPAIR);
        queue.pop(); // pop the current pair out
    }
}

std::ostream& operator<<(std::ostream& os, const pair p)
{
    os << p.first << " - " << p.second;
    return os;
}

int main()
{
    int rockCount;
    std::cin >> rockCount;

    while (rockCount--)
    {
        int x,y;
        std::cin >> x >> y;
        plane[x][y] = -1;
    }

    // std::cout << HasNeighbors(2, 1, -1) << std::endl;

    int counter = 0;
    bool isFirstVal = true;
    std::queue<pair> checkNext;
    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
        {
            if (plane[i][j] != -1) continue;
            if (HasNeighbors(i, j, -2) == NULLPAIR && !isFirstVal)
                counter++;
            plane[i][j] = -2;
            ApplyNeighbors(i, j, checkNext);
            isFirstVal = false;
        }
    std::cout << counter << std::endl;
}
