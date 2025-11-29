#include <bits/stdc++.h>

typedef std::vector<int> vector;
typedef std::vector<std::vector<int>> vector2d;
typedef std::pair<int, int> pii;
typedef std::tuple<int, int, int> edge; // (weight, v1, v2)

int getRoot_dj(int node, vector& djset)
{
    if (djset[node] == -1) return node;
    int root = getRoot_dj(djset[node], djset);
    djset[node] = root; // optimize be shortening the tree
    return root;
}

bool union_dj(int node1, int node2, vector& djset)
{
    int root1 = getRoot_dj(node1, djset);
    int root2 = getRoot_dj(node2, djset);
    if (root1 == root2) return false; // union these two will create a cycle which is unecessary
    djset[root2] = root1;
    return true;
}

int main()
{
    int N;
    std::cin >> N;
    
    vector djset(N, -1);
    std::priority_queue<edge, std::vector<edge>, std::greater<edge>> nextEdge; 
    
    for (int v1 = 0; v1 < N; v1++)
    {
        for (int v2 = v1 + 1; v2 < N; v2++)
        {
            int weight;
            std::cin >> weight;
            edge e = edge(weight, v1, v2);
            nextEdge.push(e);
        }
    }
    
    // kruskal time
    int totalWeight = 0;
    while (!nextEdge.empty())
    {
        edge currentEdge = nextEdge.top();
        nextEdge.pop();
        
        int weight = std::get<0>(currentEdge);
        int v1 = std::get<1>(currentEdge);
        int v2 = std::get<2>(currentEdge);
        
        // check no cycle
        bool success = union_dj(v1, v2, djset);
        if (success) totalWeight += weight;
    }
    
    std::cout << totalWeight << '\n';
}