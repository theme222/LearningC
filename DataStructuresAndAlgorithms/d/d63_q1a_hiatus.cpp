#include <iostream>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    std::set<std::pair<int, int>> yearMonth;
    
    int n, m;
    std::cin >> n >> m;
    
    while (n--)
    {
        int year, month;
        std::cin >> year >> month;
        yearMonth.insert({year, month});
    }
    
    bool isFirst = true;
    while (m--)
    {
        if (!isFirst) std::cout << ' ';
        int year, month;
        std::cin >> year >> month;
        std::pair<int, int> currentYM = {year, month};
        if (yearMonth.count(currentYM)) std::cout << "0 0";
        else 
        {
            auto firstMore = yearMonth.lower_bound(currentYM);
            if (firstMore == yearMonth.begin()) std::cout << "-1 -1";
            else
            {
                firstMore--;
                std::cout << firstMore->first << ' ' << firstMore->second;
            }
        }
        
        isFirst = false;
    }
}