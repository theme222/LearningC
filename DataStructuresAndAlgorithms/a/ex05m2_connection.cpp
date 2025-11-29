#include <bits/stdc++.h>

int N, E, K;
typedef std::vector<std::vector<int>> vector2d;

void dfsCount(int node, int depth, vector2d& adjlist, std::set<int> &kFriends) // return amount
{
    if (depth == K) 
    {
        kFriends.insert(node);
        return;
    }
    
    int total = 0;
    
    for (auto next: adjlist[node])
        dfsCount(next, depth+1, adjlist, kFriends);
}

int main()
{
    std::cin >> N >> E >> K;
    
    vector2d adjlist(N);
    for (int i = 0; i < N; i++) // every person knows themself
        adjlist[i].push_back(i);
        
    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        std::cin >> v1 >> v2;
        adjlist[v1].push_back(v2);
        adjlist[v2].push_back(v1);
    }
    
    // std::cout << "-----\n";
    int maxFriendsK = -1;
    for (int student = 0; student < N; student++)
    {
        std::set<int> kFriends;
        dfsCount(student, 0, adjlist, kFriends);
        // std::cout << a << '\n';
        maxFriendsK = std::max((int)kFriends.size(), maxFriendsK);
    }
    
    std::cout << maxFriendsK << '\n';
}