#include <iostream>
#include <string>
#include <vector>
#include <utility>

std::string grades[] = {"F", "D", "D+", "C", "C+", "B", "B+", "A", "A"};
std::vector<std::pair<std::string,std::string>> up;

int main()
{
    std::string id;
    std::cin >> id;

    while (id != "q")
    {
        std::string grade;
        std::cin >> grade;

        up.push_back(std::make_pair(id, grade));

        std::cin >> id;
    }

    while (std::cin >> id)
    {
        // std::cout << id;
        for (auto &p: up)
        {
            if (p.first == id) {
                for (int i = 0; i < 9; i++)
                {
                    if (grades[i] == p.second) {
                        p.second = grades[i+1];
                        break;
                    }
                }
            }
        }
    }

    for (auto &u: up)
    {
        std::cout << u.first << ' ' << u.second << '\n';
    }
}
