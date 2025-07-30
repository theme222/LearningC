#include <iostream>

std::string multString(char base, int num)
{
    std::string returnstr = "";
    for (int i =0; i < num; i++)
    {
        returnstr += base;
    }
    return returnstr;
}


void RLEToNorm(std::string &str)
{
    std::string outString = "";
    for (int i = 0; i < str.size(); i+=2)
    {
        int count = str[i] - '0';
        char thing = str[i+1];
        outString += multString(thing, count);
    }
    std::cout << outString << '\n';
}

void NormToRLE(std::string &str)
{
    std::string outString = "";
    char currentChar = str[0];
    int currentCount = 1;
    for (int i = 1; i < str.size(); i++)
    {
        if (currentChar == str[i])
        {
            currentCount += 1;
        }
        else
        {
            outString += (char)(currentCount + '0');
            outString += currentChar;
            currentChar = str[i];
            currentCount = 1;
        }
    }
    outString += (char)(currentCount + '0');
    outString += currentChar;
    std::cout << outString << '\n';
}

int main()
{
    std::string str;
    std::cin >> str;
    if ('0'<=str[0] && str[0]<='9') RLEToNorm(str);
    else NormToRLE(str);
}