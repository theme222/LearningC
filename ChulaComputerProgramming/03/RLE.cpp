#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;

    char currentChar = s[0];
    int currentCount = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (currentChar == s[i]) currentCount++;
        else
        {
            std::cout << currentChar << ' ' << currentCount << ' ';
            currentChar = s[i];
            currentCount = 1;
        }
    }
    std::cout << currentChar << ' ' << currentCount << '\n';
}
