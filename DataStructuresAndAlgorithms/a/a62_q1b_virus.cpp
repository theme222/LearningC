#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cassert>

bool check(std::string &virus, int left, int right)
{
    int dif = right - left;
    
    if (dif == 1)
        return virus[left] == '0' && virus[right] == '1';
    
    bool checkLeft = check(virus, left, left + (dif/2));
    // attempt reverse
    std::reverse(virus.begin() + left, virus.begin() + left + (dif/2) + 1);
    checkLeft |= check(virus, left, left + (dif/2));
    std::reverse(virus.begin() + left, virus.begin() + left + (dif/2) + 1);
    
    return checkLeft && check(virus, left+ (dif/2)+1, right);
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    
    while (n--)
    {
        std::string current(1<<k, 'x');
        for (int i = 0; i < (1<<k); i++)
        {
            char a;
            std::cin >> a;
            current[i] = a;
        }
        
        if (check(current, 0, current.size()-1)) puts("yes");
        else puts("no");
    }
}

