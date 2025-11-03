#include <iostream>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int N;
    std::cin >> N;
    
    std::set<int> dup;
    while (N--)
    {
        int in;
        std::cin >> in;
        if (dup.count(in) == 1)
        {
            puts("NO");
            return 0;
        }
        dup.insert(in);
    }
    puts("YES");
}