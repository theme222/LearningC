#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#define sum(vec) std::accumulate(vec.begin(), vec.end(), 0)

typedef std::vector<std::vector<int>> vecvec;
vecvec fit_vec;

void FirstFit()
{
    int currNum;
    while (std::cin >> currNum)
    {
        bool foundFit = false;
        for (auto &vec: fit_vec)
        {
            if (sum(vec) + currNum <= 100)
            {
                vec.push_back(currNum);
                foundFit = true;
                break;
            }
        }
        if (!foundFit) fit_vec.push_back(std::vector<int>(1,currNum));
    }
}

void BestFit()
{
    int currNum;
    while (std::cin >> currNum)
    {
        bool foundFit = false;
        int bestFitIndex = -1;
        int bestFitMax = 0;

        for (int i = 0; i < fit_vec.size(); i++)
        {
            int totalSum = sum(fit_vec[i]) + currNum;
            if (totalSum <= 100 && totalSum > bestFitMax)
            {
                bestFitMax = totalSum;
                bestFitIndex = i;
                foundFit = true;
            }
        }

        if (foundFit) fit_vec[bestFitIndex].push_back(currNum);
        else fit_vec.push_back(std::vector<int>(1,currNum));
    }
}

bool SortFunction(std::vector<int>& a, std::vector<int>& b)
{
    std::sort(a.begin(), a.end()); // sort the inner vectors in ascending order
    std::sort(b.begin(), b.end()); // sort the inner vectors in ascending order
    if (sum(a) == sum(b))
    {
        if (a.size() == b.size())
        {
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] == b[i]) continue;
                else return a[i] < b[i];
            }
            return true;
        }
        else return a.size() < b.size();
    }
    else return sum(a) > sum(b);
}

int main()
{
    std::string a;
    std::cin >> a;
    if (a == "first") FirstFit();
    else BestFit();

    // Print vector in descending order
    std::sort(fit_vec.begin(), fit_vec.end(), SortFunction);
    for (auto& vec: fit_vec)
    {
        printf("%d", vec[0]);
        for (int i = 1; i < vec.size(); i++)
            printf(" %d", vec[i]);
        puts("");
    }
}
