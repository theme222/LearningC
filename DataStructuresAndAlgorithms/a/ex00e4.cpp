#include <vector>
#include <string>
#include <iostream>

int choice, total; // choice is number of white

void combi(int length, int whiteCount, int blackCount, std::vector<int> &vec)
{
    if (length == total)
    {
        bool isFirst = true;
        for (auto a: vec)
        {
            if (!isFirst) std::cout << ' ';
            std::cout << a;
        }
        std::cout << '\n';
    }
    else 
    {
        if (whiteCount < choice)
        {
            vec[length] = 1;
            combi(length+1, whiteCount+1, blackCount, vec);
        }
        if (blackCount < total - choice)
        {
            vec[length] = 0;
            combi(length+1, whiteCount, blackCount+1, vec);
        }
        vec[length] = -1;
    }
}

int main()
{
    std::ios_base::sync_with_stdio('\0'); std::cin.tie(nullptr);
    std::cin >> choice >> total;
    
    
    std::vector<int> vec(total, -1);
    combi(0, 0, 0, vec);
}