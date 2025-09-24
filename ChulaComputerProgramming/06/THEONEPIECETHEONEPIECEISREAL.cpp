#include <bits/stdc++.h>

std::vector<std::string> list;

std::string spin(std::string str)
{
    std::string sub = str.substr(1);
    sub += str[0];
    return sub;
}

int main()
{
    std::string input;
    std::cin >> input;

    input += "$";

    for (int i = 0; i < input.size(); i++)
    {
        list.push_back(input);
        input = spin(input);
    }

    std::sort(list.begin(), list.end());

    std::string outstr = "";
    for (std::string & str: list)
    {
        outstr += (str[str.size()-1]);
    }
    std::cout << outstr;
}
