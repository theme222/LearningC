#include <iostream>
#include <vector>

std::vector<int> vec;

int bsearch()
{
    int currNum;
    std::cin >> currNum;

    int l = 0, r = vec.size(); // [l, r) so no ans

    while (l < r)
    {
        // std::cout << l << ' ' << r << '\n';
        int mid = l + (r-l)/2;
        if (vec[mid] <= currNum) // since its upper bound so <=
            l = mid + 1;
        else
            r = mid; // since its [l, r)
    }

    return l - 1;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    vec.resize(n); for (auto& a: vec) std::cin >> a;

    while (m--)
    {
        std::cout << bsearch() << '\n';
    }


}
