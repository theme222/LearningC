#include <iostream>

int main()
{
    std::string s;
    int k;
    std::cin >> s >> k;

    std::string outstr = "";

    char currentChar = s[0];
    int currentCount = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (currentChar == s[i])
            currentCount++;
        else
        {
            if (currentCount < k) outstr += s.substr(i-currentCount, currentCount);
            currentChar = s[i];
            currentCount = 1;
        }
    }
    if (currentCount < k) outstr += s.substr(s.size()-currentCount, currentCount);
    std::cout << outstr << std::endl;
}
