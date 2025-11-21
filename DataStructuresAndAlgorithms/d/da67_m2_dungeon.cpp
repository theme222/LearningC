#include <bits/stdc++.h>

std::vector<std::priority_queue<int, std::vector<int>, std::greater<int>>> dungeons; // <itemtype, cost (lowest first)>
std::queue<std::set<int>> demons;

int demonsKilled = 0;
int N, D; 
long long T, Z;

int main()
{
    std::ios_base::sync_with_stdio(0.f); std::cin.tie(nullptr);
    std::cin >> N >> D >> T >> Z;
    
    dungeons.resize(1000);
    for (int i = 0; i < D; i++)
    {
        int cost, type; 
        std::cin >> cost >> type;
        
        dungeons[type].push(cost);
    }
    
    for (int i = 0; i < N; i++)
    {
        int itemCount;
        std::cin >> itemCount;
        std::set<int> itemSet;
        while (itemCount--)
        {
            int item;
            std::cin >> item;
            itemSet.insert(item);
        }
        demons.push(itemSet);
    }
    
    
    while (!demons.empty())
    {
        // for (auto &s: demons)
        // {
        //     std::cout << "Demon: ";
        //     for (auto i: s)
        //         std::cout << i << ' ';
        //     std::cout << '\n';
        // }
        
        auto &demon = demons.front();
        // for (auto a: *demonItr)
        // {
        //     std::cout << a;
        // }
        
        long long currentCost = 0;
        for (int weapon: demon)
        {
            // std::cout << "weapon: " << weapon << '\n';
            if (dungeons[weapon].empty()) 
            {
                currentCost= 1e10;
                break; // not enough weapon
            }
            currentCost += dungeons[weapon].top();
            dungeons[weapon].pop();
        }
        
        if (currentCost > T) break; // no more strength
        
        T -= currentCost;
        demons.pop();
        demonsKilled++;
    }
    
    std::cout << demonsKilled << '\n';
}