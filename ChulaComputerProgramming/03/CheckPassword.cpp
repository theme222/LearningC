#include <cctype>
#include <iostream>

inline bool IsNum(char a)
{
    return a >= '0' && a <= '9';
}

inline bool IsLowercase(char a)
{
    return a >= 'a' && a <= 'z';
}

inline bool IsUppercase(char a)
{
    return a >= 'A' && a <= 'Z';
}

inline bool IsSpecial(char a)
{
    return !(IsNum(a) || IsLowercase(a) || IsUppercase(a));
}

int main()
{
    std::string s;

    while (std::getline(std::cin, s))
    {
        int size = s.size();
        bool hasLower = false;
        bool hasUpper = false;
        bool hasNum = false;
        bool hasSpecial = false;

        for (int i = 0; i < s.size(); i++)
        {
            hasLower = hasLower || IsLowercase(s[i]);
            hasUpper = hasUpper|| IsUppercase(s[i]);
            hasNum = hasNum || IsNum(s[i]);
            hasSpecial = hasSpecial || IsSpecial(s[i]);
        }

        if (size >= 12 && hasUpper && hasLower && hasNum && hasSpecial)
            std::cout << ">> strong\n";
        else if (size >= 8 && hasUpper && hasLower && hasNum)
            std::cout << ">> weak\n";
        else
            std::cout << ">> invalid\n";
    }
}
