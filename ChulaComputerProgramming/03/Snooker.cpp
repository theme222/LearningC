#include <iostream>
#include <stdexcept>

int GetScore(char color)
{
    switch(color)
    {
        case 'R': return 1;
        case 'Y': return 2;
        case 'G': return 3;
        case 'N': return 4;
        case 'B': return 5;
        case 'P': return 6;
        case 'K': return 7;
        default: throw std::invalid_argument("Invalid color");
    }
}

int main()
{
    int testcases;
    std::string s;
    std::cin >> testcases;
    std::cin.ignore();

    std::string correct = "YGNBPK";

    while (testcases--)
    {
        std::getline(std::cin, s);
        int correctIndex = 0;
        int score = 0;
        bool isValid = true;
        bool rRound = true;
        bool doCorrect = false;

        if (s[0] != 'R')
        {
            puts("WRONG_INPUT");
            break;
        }
        for (int i = 0; i <= s.size(); i+=2)
        {
            score += GetScore(s[i]);
            if (doCorrect)
            {
                if (correct[correctIndex] != s[i])
                {
                    isValid = false;
                    break;
                }
                correctIndex++;
            }
            else
            {
                if (rRound && s[i] == 'R' )
                {
                    rRound = !rRound;
                    if (i +2 < s.size() && s[i+2] == 'R')
                    {
                        isValid = false;
                        break;
                    }
                }
                else if (rRound)
                {
                    doCorrect = true;
                    if (correct[correctIndex] != s[i])
                    {
                        isValid = false;
                        break;
                    }
                    correctIndex++;
                }
                else
                    rRound = !rRound;
            }
        }
        if (isValid)
            std::cout << score << '\n';
        else
            puts("WRONG_INPUT");
    }
}
