#include <bits/stdc++.h>

int R, C, T;
int country[505][505];

typedef std::tuple<int, int, int> coordsDay; // (y, x, day)

const coordsDay up(1,0,1);
const coordsDay down(-1,0,1);
const coordsDay left(0,-1,1);
const coordsDay right(0,1,1);

coordsDay operator+(coordsDay a, coordsDay b)
{
    return coordsDay(
        std::get<0>(a) + std::get<0>(b),
        std::get<1>(a) + std::get<1>(b),
        std::get<2>(a) + std::get<2>(b)
    );
}

bool validCoord(coordsDay a)
{
    return ( 
        0 <= std::get<0>(a) &&
        std::get<0>(a) < R &&
        0 <= std::get<1>(a) &&
        std::get<1>(a) < C &&
        std::get<2>(a) <= T
    );
}

int main()
{
    std::cin >> R >> C >> T;
    
    std::queue<coordsDay> nextTown;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int val;
            std::cin >> val;
            if (val == 1) 
            {
                nextTown.push(coordsDay(i, j, 0));
                country[i][j] = 0; // will set it inside the bfs loop
                continue; 
            }
            country[i][j] = val;
        }
    }
    
    while (!nextTown.empty())
    {
        coordsDay currTown = nextTown.front();
        nextTown.pop();
        
        if (!validCoord(currTown)) continue;
        int r = std::get<0>(currTown), c = std::get<1>(currTown), t = std::get<2>(currTown);
        
        if (country[r][c] == 2) continue; // is mountain
        if (country[r][c] == 1) continue; // already infected
        
        country[r][c] = 1;
        
        nextTown.push(currTown + up);
        nextTown.push(currTown + down);
        nextTown.push(currTown + left);
        nextTown.push(currTown + right);
    }
    
    int count = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (country[i][j] == 1) count++;
    std::cout << count << '\n';
}