#include <iostream>
#include <vector>
#include <set>

std::set<std::string> won;
std::set<std::string> lost;

int main()
{
    std::string winner, loser;
    while (std::cin >> winner)
    {
        std::cin >> loser;
        won.insert(winner);
        lost.insert(loser);
    }

    std::vector<std::string> out;
    for (const std::string & team: won)
    {
        if (lost.count(team) != 0) continue;
        out.push_back(team);
    }

    if (out.empty()) std::cout << "none";
    for (auto &a: out)
        std::cout << a << ' ';
}
