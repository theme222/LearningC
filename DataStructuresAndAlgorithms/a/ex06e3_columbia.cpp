#include <bits/stdc++.h>

typedef std::vector<std::vector<int>> vector2d;
typedef std::pair<int, int> pii;

const pii up(1,0);
const pii down(-1,0);
const pii left(0,-1);
const pii right(0,1);

int R, C;

int GetCityIndex(pii a)
{
    int r = a.first;
    int c = a.second;
    return r*R + c;
}

pii operator+(pii a, pii b)
{
    return pii(a.first + b.first, a.second + b.second);
}

bool ValidIndex(pii a)
{
    int r = a.first;
    int c = a.second;
    return ( 0 <= r && r < R && 0 <= c && c < C  );
}


int main()
{
    std::cin >> R >> C;

    vector2d city(R, std::vector<int>(C));
    std::vector<int> dist(R*C, 1e9);
    std::vector<std::vector<pii>> adjlist(R*C); // weight, node

    for (auto& a: city)
        for (auto& b: a)
            std::cin >> b;

    city[0][0] = 0;

    // construct adj list
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            pii current(i, j);
            if (ValidIndex(current + up))
                adjlist[GetCityIndex(current)].push_back(pii(city[i+1][j], GetCityIndex(current + up)));
            if (ValidIndex(current + down))
                adjlist[GetCityIndex(current)].push_back(pii(city[i-1][j], GetCityIndex(current + down)));
            if (ValidIndex(current + left))
                adjlist[GetCityIndex(current)].push_back(pii(city[i][j-1], GetCityIndex(current + left)));
            if (ValidIndex(current + right))
                adjlist[GetCityIndex(current)].push_back(pii(city[i][j+1], GetCityIndex(current + right)));
        }
    }

    std::set<pii> nextNode;
    nextNode.insert(pii(0, 0));
    dist[0] = 0;

    while (!nextNode.empty())
    {
        auto it = nextNode.begin();
        int weight = it->first, node = it->second;
        nextNode.erase(it);

        for (auto next: adjlist[node])
        {
            if (dist[next.second] > weight + next.first)
            {
                auto nextIt = nextNode.find(pii(dist[next.second], next.second));
                if (nextIt != nextNode.end()) nextNode.erase(nextIt);

                dist[next.second] = weight + next.first;
                nextNode.insert(pii(dist[next.second], next.second));
            }
        }
    }

    int counter = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (j != 0) std::cout << ' ';
            std::cout << dist[counter];
            counter++;
        }
        std::cout << '\n';
    }

}
