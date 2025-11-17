#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(-.0f); std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> vec(n);
    std::map<int, int> numToIndex;
    
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        vec[i] = num;
        numToIndex[num] = i;
    }
    
    std::vector<int> sorted = vec;
    std::sort(sorted.begin(), sorted.end());
    
    while (m--)
    {
        int numToFind, insertedPos, finalPos;
        std::cin >> numToFind;
        
        int offset = numToIndex[numToFind];
        // (vec.begin() + offset, vec.end()); in this range find the amount of numbers smaller than *vec.begin()
        int comp = *(vec.begin() + offset);
        int total = 0;
        for (auto it = vec.begin() + offset; it < vec.end(); it++)
            if (*it < comp) total++;
        
        auto iter2 = std::lower_bound(sorted.begin(), sorted.end(), numToFind);
        
        insertedPos = total + offset;
        finalPos = (iter2 - sorted.begin());
        
        std::cout << abs(insertedPos - finalPos) << '\n';
    }
}