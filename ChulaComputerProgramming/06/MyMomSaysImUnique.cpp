#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> vec;
int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);


    int a;
    while (std::cin >> a)
        vec.push_back(a);

    std::sort(vec.begin(), vec.end());

    int prevNum = -1;
    int count = 0;
    for (auto a: vec)
    {
        if (a != prevNum) count++;
        prevNum = a;
    }

    std::cout << count << std::endl;
    std::cout << vec[0];
    prevNum = vec[0];
    int outCount = 1;
    for (int i = 1; i < vec.size() && outCount < 10; i++)
    {
        if (vec[i] == prevNum) continue;
        std::cout << ' ' << vec[i];
        prevNum = vec[i];
        outCount++;
    }

}
