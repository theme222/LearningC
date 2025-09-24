#include <iostream>
#include <set>
#include <vector>

std::set<int> seen;
int main()
{
    int a, count = 0;
    while (std::cin >> a)
    {
        count++;
        if (seen.count(a) == 1)
        {
            std::cout << count;
            return 0;
        }
        seen.insert(a);
    }

    std::cout << "-1";

}
