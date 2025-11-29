#include <bits/stdc++.h>

typedef std::vector<int> vector;
typedef std::vector<std::vector<int>> vector2d;
typedef std::pair<int, int> pii;

void bfs(vector &component, vector2d &adjlist, int node, int currentComponent)
{
    std::queue<pii> nextCheck;
    
    nextCheck.push(pii(node, -1));
    
    while (!nextCheck.empty())
    {
        pii pair = nextCheck.front();
        nextCheck.pop();
        int curr = pair.first, prev = pair.second;
        
        if (component[curr] != -1) continue; // same node previously visited 
        component[curr] = currentComponent;
        
        for (auto next: adjlist[curr])
            nextCheck.push(pii(next, curr));
    }
    
}

int main()
{
    int V, E;
    std::cin >> V >> E;
    
    vector component(V, -1);
    vector2d adjlist(V);
    
    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        std::cin >> v1 >> v2;
        v1--; v2--; // initial index was 1
        adjlist[v1].push_back(v2);
        adjlist[v2].push_back(v1);
    }
    
    // get components
    int currentComponent = 1;
    for (int i = 0; i < V; i++)
    {
        if (component[i] != -1) continue;
        bfs(component, adjlist, i, currentComponent);
        currentComponent++;
    }
    
    // for (auto a: component) std::cout << ' ' << a;
    // std::cout << '\n';
    
    std::cout << currentComponent-1 << '\n';
}