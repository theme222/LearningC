#include <bits/stdc++.h>

typedef std::vector<std::vector<int>> matrix;
typedef std::pair<int, int> pii;


bool findCycle(matrix& adjlist, std::vector<bool>& visited)
{
    std::queue<pii> nextToCheck; // (currNode, prevNode);
    for (int i = 0; i < adjlist.size(); i++)
    {
        if (visited[i]) continue;
        nextToCheck.push(pii(i, -1));
        
        while (!nextToCheck.empty())
        {
            pii pair = nextToCheck.front();
            nextToCheck.pop();
            
            int curr = pair.first, prev = pair.second;
            visited[curr] = true;
            
            for (auto next: adjlist[curr])
            {
                if (visited[next]) 
                {
                    if (next != prev)
                        return true; // found cycle?
                }
                else 
                    nextToCheck.push(pii(next, curr));
            }
        }
    }
    return false;
}


int main()
{
    int T;
    std::cin >> T;
    
    while (T--)
    {
        int N, E;
        std::cin >> N >> E;
        matrix adjlist(N);
        std::vector<bool> visited(N);
        
        for (int e = 0; e < E; e++)
        {
            int v1, v2;
            std::cin >> v1 >> v2;
            adjlist[v1].push_back(v2);
            adjlist[v2].push_back(v1);
        }
        
        bool isCycle = findCycle(adjlist, visited);
        std::cout << (isCycle ? "YES" : "NO") << '\n';
    }
}