#include <bits/stdc++.h>

std::vector<int> steps;
std::vector<std::string> names;
std::vector<std::pair<std::string, int>> prizes; // prize val

std::vector<std::tuple<int, std::string, std::string>> winners; // value prize name

int main()
{
    int N, M, Q;
    std::cin >> N >> M >> Q;

    for (int i = 0; i < N; i++)
    {
        std::string name;
        std::cin >> name;
        names.push_back(name);
    }

    for (int i = 0; i < N; i++)
    {
        std::string prize;
        int value;
        std::cin >> prize >> value;
        prizes.push_back({prize, value});
    }

    for (int i = 0; i < M; i++)
    {
        int a;
        std::cin >> a;
        steps.push_back(a - 1); // minus 1 because the bestard made it one indexed
    }

    for (int start = 0; start < N; start++)
    {
        int currCol = start;

        for (int i = 0; i < M; i++)
        {
            if (steps[i] == currCol)
            {
                currCol = steps[i] + 1;
            }
            else if (steps[i] + 1 == currCol)
            {
                currCol = steps[i];
            }
        }

        winners.push_back(
            {
                -prizes[currCol].second,
                prizes[currCol].first,
                names[start]
            });
    }
    
    std::sort(winners.begin(), winners.end());

    for (int i = 0; i < Q; i++)
    {
        std::string mode, name;
        int rank;
        std::cin >> mode;
        if (mode == "rank")
        {
            std::cin >> rank;
            std::cout << std::get<2>(winners[rank-1]) << ' '
                      << std::get<1>(winners[rank-1])
                      << '\n';
        }
        else if (mode == "name")
        {
            std::cin >> name;
            for (auto &winner: winners)
            {
                if (std::get<2>(winner) == name)
                {
                    std::cout << std::get<1>(winner) << ' '
                              << (-std::get<0>(winner))
                              << '\n';
                }
            }
        }
    }
}