#include <bits/stdc++.h>

typedef std::vector<std::vector<int>> vector2d;

int N;

bool dfsCheckCycleLen(int prev, int node, std::vector<int> &path, vector2d &adjlist, std::vector<bool> visited) // returns true if it finds a cycle
{
    path.push_back(node);
    if (visited[node])
        return true;
    
    visited[node] = true;
    
    for (auto next: adjlist[node])
        if (next != prev)
            if ( dfsCheckCycleLen(node, next, path, adjlist, visited) )
                return true;
    
    path.pop_back();
    return false; // no cycle in any of the nextss
}

int main()
{
    std::cin >> N;
    
    vector2d adjlist(N);
    std::vector<bool> visited(N);
    std::vector<int> path;
    
    for (int i = 0; i < N; i++)
    {
        int v1, v2;
        std::cin >> v1 >> v2;
        adjlist[v1].push_back(v2);
        adjlist[v2].push_back(v1);
    }
    
    dfsCheckCycleLen(-1, 0, path, adjlist, visited);
    
    int end = path[path.size()-1];
    auto it = std::find(path.begin(), path.end(), end);
    std::cout << (path.end() - it - 1) << '\n'; // not including the last value (repeated) in the path
}