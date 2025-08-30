#include <iostream>
#include <cctype>
#include <algorithm>

std::string vowels = "aeiou";

int GetStartOfVowels(std::string& str)
{
    for (int i = 0; i < str.size(); i++)
        if (vowels.find(str[i]) != std::string::npos)
            return i;
    return -1;
}

int main()
{
    std::string instr;
    std::getline(std::cin, instr);

    // find the first space

    int firstEndIndex = 0;
    for (; firstEndIndex < instr.size(); firstEndIndex++)
        if (instr[firstEndIndex] == ' ')
            break;

    std::string firstword = instr.substr(0,firstEndIndex);

    // find the last space

    int lastStartIndex = instr.size() - 1;
    for (; lastStartIndex >= 0; lastStartIndex--)
        if (instr[lastStartIndex] == ' ')
            break;

    std::string lastword = instr.substr(lastStartIndex+1);

    std::string consFirstWord = firstword.substr(0,GetStartOfVowels(firstword));
    std::string consLastWord = lastword.substr(0,GetStartOfVowels(lastword));

    std::string vowelFirstWord = firstword.substr(GetStartOfVowels(firstword));
    std::string vowelLastWord = lastword.substr(GetStartOfVowels(lastword));

    firstword = consFirstWord + vowelLastWord;
    lastword = consLastWord + vowelFirstWord;

    // std::cout << consFirstWord << ' ' << vowelFirstWord << ' ' << consLastWord << ' ' << vowelLastWord << '\n';
    std::cout << firstword << instr.substr(firstEndIndex, lastStartIndex - firstEndIndex + 1) << lastword << '\n';

}
