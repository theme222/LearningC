#include <bits/stdc++.h>

using std::vector;
typedef std::pair<int, int> pii; // weight node

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    int n, initialCost;
    std::cin >> n >> initialCost;

    vector<vector<pii>> adjlist(n+1); // 0 is unused
    adjlist[1].push_back(pii(initialCost, 2));
    adjlist[2].push_back(pii(initialCost, 1));

    for (int i = 3; i <= n; i++)
    {
        vector<int> dist(n+1, 1e9); // 0 is unused
        vector<bool> visited(n+1); // 0 is unused

        int bridgeCount;
        std::cin >> bridgeCount;

        while (bridgeCount--)
        {
            int v, weight;
            std::cin >> v >> weight;
            adjlist[i].push_back(pii(weight, v));
            adjlist[v].push_back(pii(weight, i));
        }

        std::set<pii> nextNode;
        nextNode.insert(pii(0, 1));

        // dijkstra
        while (!nextNode.empty())
        {
            auto itr = nextNode.begin();
            int weight = itr->first, currentNode = itr->second;
            nextNode.erase(itr);
            dist[currentNode] = weight;
            visited[currentNode] = true;

            for (auto nextPair: adjlist[currentNode])
            {
                if (visited[nextPair.second]) continue;
                if (dist[nextPair.second] > weight + nextPair.first)
                {
                    auto nextIt = nextNode.find(pii(dist[nextPair.second], nextPair.second));
                    if (nextIt != nextNode.end()) nextNode.erase(nextIt);
                    dist[nextPair.second] =  weight + nextPair.first;
                    nextNode.insert(pii(dist[nextPair.second], nextPair.second));
                }
            }
        }

        if (i != 3) std::cout << ' ';
        std::cout << dist[2];
    }
}
