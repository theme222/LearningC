#include <iostream>

int count[26];

char ForceLower(char c)
{
    if ('a' <= c && c <= 'z') return c;
    if ('A' <= c && c <= 'Z') return c + 'a' - 'A';
    return '\0';
}

int main()
{
    std::string str;
    std::getline(std::cin, str);
    for (int i = 0; i < str.size(); i++)
        if (ForceLower(str[i]))
            count[ForceLower(str[i]) - 'a']++;
    for (int i = 0; i < 26; i++)
        if (count[i]) std::cout << (char)(i+'a') << " -> " << count[i] << '\n';
}
