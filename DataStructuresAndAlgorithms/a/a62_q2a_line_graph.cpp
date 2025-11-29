#include <bits/stdc++.h>

typedef std::vector<std::vector<int>> vector2d;
typedef std::pair<int, int> pii;

bool CheckLineGraph(int node, std::vector<bool>& visited, vector2d& adjlist)
{
    bool isLine = true;
    std::queue<pii> nextCheck;
    
    nextCheck.push(pii(node, -1));
    while (!nextCheck.empty())
    {
        pii pair = nextCheck.front();
        int curr = pair.first, prev = pair.second;
        nextCheck.pop();
        std::cout << curr << ' ' << prev << " kjfdsljsfdlkfdsk\n";
        
        isLine = isLine && adjlist[curr].size() <= 2; // degree of all nodes in the graph must be <= 2
        visited[curr] = true;
        
        for (auto next: adjlist[curr])
        {
            if (next != prev && visited[next]) // cycle
                isLine = false;
            if (!visited[next]) nextCheck.push(pii(next, curr));
        }
    }
    
    return isLine;
}

int main()
{
    int V, E;
    std::cin >> V >> E;
    
    vector2d adjlist(V);
    std::vector<bool> visited(V);
    
    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        std::cin >> v1 >> v2;
        adjlist[v1].push_back(v2);
        adjlist[v2].push_back(v1);
    }
    
    
    int lineGraphCount = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i]) continue;
        lineGraphCount += CheckLineGraph(i, visited, adjlist);
    }
    
    std::cout << lineGraphCount << '\n';
}