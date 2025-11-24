#include <iostream>
#include <vector>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> vec(n);
    for (auto &a: vec) std::cin >> a;
    
    while (m--)
    {
        int currNum;
        std::cin >> currNum;
        
        int l = 0, r = vec.size();
        
        while (l < r)
        {
            std::cout << l << ' ' << r 
            int mid = l + ((r-l)/2);
            if (vec[mid] == currNum) 
                l = r = mid;
            else if (vec[mid] > currNum) 
                r = mid-1;
            else if (vec[mid] < currNum)
                l = mid;
        }
        
        if (vec[l] == currNum) std::cout << vec[l] << '\n';
        else if (l == 0) std::cout << "-1\n";
        else std::cout << vec[l-1] << '\n';
    }

    
}