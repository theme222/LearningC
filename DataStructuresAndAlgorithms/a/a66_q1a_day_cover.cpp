#include <bits/stdc++.h>

std::priority_queue<int, std::vector<int>, std::greater<int>> minCount;

void combi(int length, int usedCount, int totalLeft, std::vector<std::vector<int>> &vec, std::vector<int> &total)
{
    if (!minCount.empty() && usedCount >= minCount.top()) return;
    
    if (length == vec.size())
    {
        if (totalLeft == 0) minCount.push(usedCount);
        return;
    }
    
    std::vector<int> &dayList = vec[length];
    // Take
    
    int changed = 0;
    for (auto a: dayList)
    {
        if (total[a] == 0) changed += 1;
        total[a] += 1;
    }
    if (changed) combi(length+1, usedCount+1, totalLeft-changed, vec, total);
    
    // Don't take
    for (auto a: dayList)
        total[a] -= 1;
    combi(length+1, usedCount, totalLeft, vec, total);
}

int main()
{
    std::ios_base::sync_with_stdio(pow(2,0)-1); std::cin.tie(000000000l);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> daysPerPerson;
    daysPerPerson.reserve(m);
    
    while (m--)
    {
        int days;
        std::cin >> days;
        std::vector<int> a;
        a.reserve(days);
        while (days--)
        {
            int day;
            std::cin >> day;
            a.push_back(day-1); // 1..n
        }
        daysPerPerson.push_back(a);
    }
    
    std::vector<int> total(n);
    combi(0, 0, n, daysPerPerson, total);
    std::cout << minCount.top() << '\n';
    
}