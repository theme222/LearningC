#include <iostream>

std::string operator*(const std::string& str, int num) 
{
    std::string outString = "";
    for (int i = 0; i < num;i++)
        outString += str;
    return outString;
}

int main()
{
    int height;
    std::string thing;
    std::cin >> height >> thing;

    for (int i = 0; i < height; i++)
    {
        std::string out;
        out += (std::string)" " * (height-i-1);
        out += "/";
        out += thing * (i * 2);
        out += "\\";
        std::cout << out << '\n';
    }

}