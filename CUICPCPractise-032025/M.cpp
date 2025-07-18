#include <iostream>
#include <unordered_set>

int levels[200001];
std::unordered_set<int> neighbors[200001];
bool visitedNodes[200001];

void SetLevel(int currentNum)// technically dfs omegalul
{
    for (auto a: neighbors[currentNum])
    {
        if (currentNum > a) continue;
        levels[a] = levels[currentNum]+1;
        SetLevel(a);
    }
}

int main()
{
    int nodes;
    scanf("%d", &nodes);
    int edges = nodes-1;

    for (int i = 0; i < edges; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        neighbors[a].insert(b);
        neighbors[b].insert(a);
    }

    SetLevel(1);

    int currentNode;
    scanf("%d", &currentNode);
    if (currentNode != 1)
    {
        puts("No");
        exit(0);
    }
    nodes--;

    int currentLevel = 0;
    visitedNodes[1] = true;
    while (nodes--)
    {
        int currentNode;
        scanf("%d", &currentNode);
        // std::cout << nodes << std::endl;
        bool hasVisistedNeighbor = false;
        for (auto a: neighbors[currentNode])
            hasVisistedNeighbor = hasVisistedNeighbor || visitedNodes[a];

        if ((levels[currentNode] == currentLevel || levels[currentNode] == currentLevel+1) && hasVisistedNeighbor)
            currentLevel = levels[currentNode];
        else
        {
            puts("No");
            exit(0);
        }
        visitedNodes[currentNode] = true;

    }
    puts("Yes");
}
