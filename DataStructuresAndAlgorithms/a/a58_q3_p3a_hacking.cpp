#include <bits/stdc++.h>
using std::vector;

typedef std::pair<int, int> pii; // weight, node

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    vector<int> firstAttack(k);
    for (int i = 0; i < k; i++)
    {
        int a;
        std::cin >>a;
        firstAttack[i] = a+1;
    }

    vector<int> cost(n+1); // 0th server will have a cost being zero and this "server" will connect to the first attack servers.
    cost[0] = 0;
    for (int i = 1; i < n+1; i++) std::cin >> cost[i];


    vector<vector<pii>> adjlist(n+1);

    // add normal cables
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        std::cin >> v1 >> v2;
        v1++; v2++; // turn zero based index to one based
        adjlist[v1].push_back(pii(cost[v2], v2));
        adjlist[v2].push_back(pii(cost[v1], v1));
    }

    // add first attack
    for (auto node: firstAttack)
        adjlist[0].push_back(pii(cost[node], node));

    vector<int> dist(n+1, 1e9);
    vector<bool> visited(n+1);
    std::set<pii> nextNode;
    nextNode.insert(pii(0, 0));

    while (!nextNode.empty())
    {
        auto itr = nextNode.begin();
        int weight = itr->first, currentNode = itr->second;
        dist[currentNode] = weight;
        visited[currentNode] = true;
        nextNode.erase(itr);

        for (auto &next: adjlist[currentNode])
        {
            if (visited[next.second]) continue;
            auto nextIt = nextNode.find(pii(dist[next.second], next.second));
            if (nextIt != nextNode.end())
                nextNode.erase(nextIt);

            if (dist[next.second] > weight + next.first)
                dist[next.second] = weight + next.first;

            nextNode.insert(pii(dist[next.second], next.second));
        }
    }


    std::cout << *std::max_element(dist.begin(), dist.end()) << '\n';

}
