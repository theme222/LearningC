#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdexcept>

int translator(std::string word)
{
    if (word == "soon") return 0;
    if (word == "neung") return 1;
    if (word == "song") return 2;
    if (word == "sam") return 3;
    if (word == "si") return 4;
    if (word == "ha") return 5;
    if (word == "hok") return 6;
    if (word == "chet") return 7;
    if (word == "paet") return 8;
    if (word == "kao") return 9;
    if (word == "et") return 1;
    if (word == "yi") return 2;
    if (word == "sip") return 10;
    if (word == "roi") return 100;
    if (word == "phan") return 1000;
    if (word == "muen") return 10000;
    if (word == "saen") return 100000;
    if (word == "lan") return 1000000;
    throw std::invalid_argument("Invalid word");
}

bool isModifier(std::string word)
{
    if (word == "sip") return true;
    if (word == "roi") return true;
    if (word == "phan") return true;
    if (word == "muen") return true;
    if (word == "saen") return true;
    if (word == "lan") return true;
    return false;
}

int main()
{
    std::string thai;
    std::getline(std::cin, thai);

    while (thai != "q")
    {
        std::stringstream ss(thai);
        std::string word;
        int pastNum = -1; // -1 means no past num
        int total = 0;

        while (ss >> word)
        {
            if (isModifier(word))
            {
                int add = std::clamp(pastNum, 1, 9);
                add *= translator(word);
                total += add;
                pastNum = -1;
            }
            else
            {
                pastNum = translator(word);
            }
        }

        total += std::clamp(pastNum, 0, 9);

        std::cout << total << '\n';
        std::getline(std::cin, thai);
    }
}
