#include <iostream>
#include <algorithm>
#include <vector>

int order[4] = {0, 1, 2, 3};


int GetIndex(std::string val, std::vector<std::string> vec)
{
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == val) return i;
    return -1;
}

void SetOrder(int &a, int &b, int &c, int &d, std::vector<std::string>& vec, std::vector<std::string>& vec1)
{
    a = GetIndex(vec1[0], vec);
    b = GetIndex(vec1[1], vec);
    c = GetIndex(vec1[2], vec);
    d = GetIndex(vec1[3], vec);
}

int main()
{
    std::vector<std::string> names;
    int favNum;

    std::cin >> favNum;

    for (int i = 0; i < 4; i++)
    {
        std::string n;
        std::cin >> n;
        names.push_back(n); 
    }

    std::vector<std::string> namesBefore = names;

    std::sort(names.begin(), names.end());

    int start = GetIndex(names[favNum - 1], namesBefore);
    std::cout << start << std::endl;

    int delta, theta, bigdelta, psi;
    // delta 0
    // theta 1
    // bigdelta 2
    // psi 3

    bool omega = false, mu = false, xi = false;

    
    

}