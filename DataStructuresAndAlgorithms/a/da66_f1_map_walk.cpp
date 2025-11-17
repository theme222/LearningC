#include <bits/stdc++.h>

typedef std::pair<int, int> pos;

int area[11][11];
bool visited[11][11];

int R, C;

pos operator+(pos posA, pos posB)
{
    return pos(posA.first + posB.first, posA.second + posB.second);
}


void recurse(pos currentPos, std::string &operations)
{
    // std::cout << "rec " << currentPos.first << ' ' << currentPos.second << ' ' << operations << '\n';
    if ( 
        currentPos.first <= 0 ||
        currentPos.second <= 0 ||
        currentPos.first > R ||
        currentPos.second > C 
    ) return; // out of bounds
    
    if ( visited[currentPos.first][currentPos.second] ) return; // already visited
    if ( area[currentPos.first][currentPos.second] == 1) return; // blocked path
    
    if (currentPos == pos(R,C))
    {
        std::cout << operations << '\n';
        return;
    }
    
    visited[currentPos.first][currentPos.second] = true;
    
    // Do A (go right)
    operations.push_back('A');
    recurse(currentPos + pos(0, 1), operations);
    operations.pop_back();
    
    // Do B (go down)
    operations.push_back('B');
    recurse(currentPos + pos(1, 0), operations);
    operations.pop_back();
    
    // Do C (go up)
    operations.push_back('C');
    recurse(currentPos + pos(-1, 0), operations);
    operations.pop_back();
    
    visited[currentPos.first][currentPos.second] = false;
}

int main()
{
    std::ios_base::sync_with_stdio(.000000f); std::cin.tie(std::nullptr_t());
    std::cin >> R >> C;
    
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            std::cin >> area[i][j];
        }
    }
    
    std::string yuh;
    recurse(pos(1,1), yuh);
    std::cout << "DONE\n";
}
