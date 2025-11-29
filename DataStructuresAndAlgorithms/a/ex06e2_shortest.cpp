#include <bits/stdc++.h>

using std::vector;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> tupiii;
typedef std::vector< tupiii > vectup;

int main()
{
    int N, E, S;
    std::cin >> N >> E >> S;
    
    vectup edgelist;
    vector dist(N, INT_MAX);
    
    for (int i = 0; i < E; i++)
    {
        int v1, v2, w;
        std::cin >> v1 >> v2 >> w;
        edgelist.push_back(tupiii(v1, v2, w));
    }
    
    dist[S] = 0;
    
    // bell my ford ranger rapter
    for (int i = 0; i < N-1; i++) // run n-1 times
    {
        for (auto& edge: edgelist)
        {
            int vfrom = std::get<0>(edge); int vto = std::get<1>(edge); int weight = std::get<2>(edge);
            if (dist[vto] > dist[vfrom] + weight)
            {
                dist[vto] = dist[vfrom] + weight;
            }
        }
    }
    
    for (auto& edge: edgelist)
    {
        int vfrom = std::get<0>(edge); int vto = std::get<1>(edge); int weight = std::get<2>(edge);
        if (dist[vto] > dist[vfrom] + weight)
        {
            std::cout << "-1\n"; // negative cycle
            return 0;
        }
    }
    
    for (int d = 0; d < dist.size(); d++)
    {
        if (d != 0) std::cout << ' ';
        std::cout << dist[d];
    }
    std::cout << '\n';
    
}