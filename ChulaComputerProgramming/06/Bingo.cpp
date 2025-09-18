#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <vector>

std::vector<std::vector<std::string>> bingoCard(5, std::vector<std::string>(5)); // Init to 5 by 5 arr
std::vector<std::vector<bool>> isOpen(5, std::vector<bool>(5));

int BingoToIndex(char b)
{
    switch (b)
    {
        case 'B': return 0;
        case 'I': return 1;
        case 'N': return 2;
        case 'G': return 3;
        case 'O': return 4;
        default: throw std::invalid_argument("Bingo char not known");
    }
}

std::tuple<bool, int, int> CheckWin(int ignore)
{
    // First Int is the type of win (1 horizontal 2 vertical 3 diagonal1 4 diagonal2)
    // second int is the index

     if (ignore < 1)
     {
         // Horizontal check
         for (int i = 0; i < 5; i++)
         {
             bool rowWin = true;
             for (int j = 0; j < 5; j++)
                 rowWin = rowWin && isOpen[i][j];

             if (rowWin) return {true, 1, i};
         }
     }

     if (ignore < 2)
     {
         // Vertical check
         for (int j = 0; j < 5; j++)
         {
             bool colWin = true;
             for (int i = 0; i < 5; i++)
                 colWin = colWin && isOpen[i][j];

             if (colWin) return {true, 2, j};
         }
     }

    // Diagonal check (third value does nothing)
    if (ignore < 3)
    {
        bool diag1Win = true;
        for (int i = 0; i < 5; i++)
            diag1Win = diag1Win && isOpen[i][i];

        if (diag1Win) return {true, 3, 0};
    }

    if (ignore < 4)
    {
        bool diag2Win = true;
        for (int i = 0; i < 5; i++)
            diag2Win = diag2Win && isOpen[i][4 - i];

        if (diag2Win) return {true, 4, 0};
    }

    return {false, 0, 0};
}

bool SetOpen(std::string pos) // returns whether it set a position or not
{
    int colIndex = BingoToIndex(pos[0]);
    std::string posStr = pos.substr(1);

    for (int i = 0; i < 5; i++)
    {
        if (bingoCard[i][colIndex] == posStr)
        {
            isOpen[i][colIndex] = true;
            return true;
        }
    }

    return false;
}

std::string GetFullPos(std::string pos, int col)
{
    char b;
    switch (col)
    {
        case 0:
            b = 'B';
            break;
        case 1:
            b = 'I';
            break;
        case 2:
            b = 'N';
            break;
        case 3:
            b = 'G';
            break;
        case 4:
            b = 'O';
            break;
        default: throw std::runtime_error("uhhh");
    }
    return b + pos;
}

void PrintWin(int count)
{
    std::cout << count << '\n';

    int ignore = 0;
    std::tuple<bool, int, int> wintype = CheckWin(ignore);
    while (std::get<0>(wintype))
    {
        switch(std::get<1>(wintype))
        {
            case 1:
            {
                std::cout << GetFullPos(bingoCard[std::get<2>(wintype)][0], 0);
                for (int i = 1; i < 5; i++)
                {
                    if (bingoCard[std::get<2>(wintype)][i] == "*") continue;
                    std::cout << ", " << GetFullPos(bingoCard[std::get<2>(wintype)][i], i);
                }
                break;
            }

            case 2:
            {
                std::cout << GetFullPos(bingoCard[0][std::get<2>(wintype)], std::get<2>(wintype));
                for (int j = 1; j < 5; j++)
                {
                    if (bingoCard[j][std::get<2>(wintype)] == "*") continue;
                    std::cout << ", " << GetFullPos(bingoCard[j][std::get<2>(wintype)], std::get<2>(wintype));
                }
                break;
            }

            case 3:
            {
                std::cout << GetFullPos(bingoCard[0][0], 0);
                for (int i = 1; i < 5; i++)
                {
                    if (i == 2) continue;
                    std::cout << ", " << GetFullPos(bingoCard[i][i], i);
                }
                break;
            }

            case 4:
            {
                std::cout << GetFullPos(bingoCard[4][0], 0);
                for (int i = 3; i >= 0; i--)
                {
                    if (i == 2) continue;
                    std::cout << ", " << GetFullPos(bingoCard[i][4-i], 4-i);
                }
                break;
            }
        }

        puts("");
        ignore = std::get<1>(wintype);
        wintype = CheckWin(ignore);
        // std::cout << std::get<1>(wintype) << std::get<2>(wintype) << '\n';
    }
}

int main()
{
    std::string _temp;
    std::getline(std::cin, _temp); // B I N G O

    // input
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            std::cin >> bingoCard[i][j];

    int ballCount = 0;
    std::string pos;

    isOpen[2][2] = true; // * position

    while (std::cin >> pos)
    {
        ballCount++;
        if (SetOpen(pos)) {
            if (std::get<0>(CheckWin(0)))
            {
                PrintWin(ballCount);
                // for (auto &a: isOpen)
                // {
                //     for (auto b: a)
                //     {
                //         std::cout << b;
                //     }
                //     puts("");
                // }
                return 0;
            }
        }
    }
    throw std::invalid_argument("No Bingo :(");
}
