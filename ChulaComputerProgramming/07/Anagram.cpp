#include <set>
#include <cctype>
#include <iostream>

std::multiset<char> first;
std::multiset<char> second;

int main()
{
    std::string str;
    std::getline(std::cin, str);

    for (auto c: str)
        if (isalpha(c) || isdigit(c))
            first.insert(tolower(c));

    std::getline(std::cin, str);

    for (auto c: str)
        if (isalpha(c) || isdigit(c))
            second.insert(tolower(c));

    for (auto c: first)
    {
        if (first.count(c) != second.count(c))
        {
            std::cout << "NO";
            return 0;
        }
    }

    std::cout << "YES";

}
