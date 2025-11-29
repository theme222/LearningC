#include <bits/stdc++.h>

using std::vector;
typedef std::pair<uint64_t, int> pii; // weight node

int main()
{
    int N;
    std::cin >> N;
    
    vector<uint64_t> beauty(N);
    vector<uint64_t> dist(N, 0);
    vector<bool> visited(N);
    std::set<pii> connectedNode; 
    
    for (auto &a: beauty) std::cin >> a;
    dist[0] = 0;
    connectedNode.insert(pii(0, 0));
    
    uint64_t totalBeauty = 0;
    while (!connectedNode.empty())
    {
        auto it = (--connectedNode.end()); // get last (highest beauty)
        uint64_t d = it->first, node = it->second;
        connectedNode.erase(it);
        
        visited[node] = true;
        totalBeauty += d;
        
        for (int i = 0; i < N; i++)
        {
            if (visited[i]) continue;
            if (dist[i] < (beauty[node] ^ beauty[i])) 
            {
                auto oldNode = connectedNode.find(pii(dist[i], i));
                if (oldNode != connectedNode.end()) 
                    connectedNode.erase(oldNode);
                
                dist[i] = beauty[node] ^ beauty[i];
                connectedNode.insert(pii(dist[i], i));
            }
        }
    }
    
    std::cout << totalBeauty << '\n';
    
}
