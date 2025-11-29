#include <bits/stdc++.h>

typedef long long ll;

int adjmat[1004][1004];
typedef std::pair<ll, int> pii;

int main()
{
    int N;
    std::cin >> N;
    
    std::vector<ll> dist(N, 1e15);
    std::vector<bool> visited(N, false);
    dist[0] = 0;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> adjmat[i][j];
    
    // dijkstraskfdskdladfjslk algorithm
    
    std::set<pii> nextNode; // weight, node
    for (int i = 0; i < N; i++) nextNode.insert(pii(dist[i], i));
    
    while (!nextNode.empty())
    {
        auto it = nextNode.begin();
        ll weight = it->first, currentNode = it->second;
        nextNode.erase(it);
        visited[currentNode] = true;
        
        for (int j = 0; j < N; j++)
        {
            if (visited[j]) continue;
            if (adjmat[currentNode][j] == -1) continue; // no path
            if (dist[j] > adjmat[currentNode][j] + dist[currentNode])
            {
                auto nextIt = nextNode.find(pii(dist[j], j));
                if (nextIt != nextNode.end()) nextNode.erase(nextIt);
                dist[j] = adjmat[currentNode][j] + dist[currentNode];
                nextNode.insert(pii(dist[j], j));
            }
        }
    }

    ll maxLen = *std::max_element(dist.begin(), dist.end());
    if (maxLen > 1e12) std::cout << -1 << '\n'; 
    else std::cout << maxLen << '\n';
    
}