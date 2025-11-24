#include <iostream>
#include <cmath>

bool valid(std::string &virus, int left, int right)
{
    // std::cout << left << ' ' << right << '\n';
    int sumLeft = 0, sumRight = 0;
    int dif = right-left;
    
    if (dif == 1) return true;
    
    for (int i = left; i <= left + (dif/2); i++)
        if (virus[i] == '1') sumLeft++;
    
    for (int i = left + (dif/2)+1; i <= right; i++)
        if (virus[i] == '1') sumRight++;
    
    // std::cout << "checking: " << left << ' ' << right << " with diff " << abs(sumLeft - sumRight) << '\n';
    
    return abs(sumLeft - sumRight) <= 1 &&
            valid(virus, left, left + (dif/2)) && 
            valid(virus, left + (dif/2) + 1, right);
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    
    while (n--)
    {
        std::string virus;
        for (int i = 0; i < (1<<k); i++)
        {
            char a;
            std::cin >> a;
            virus += a;
        }
        
        if (valid(virus, 0, virus.size()-1)) puts("yes");
        else puts("no");
        
    }
    
}