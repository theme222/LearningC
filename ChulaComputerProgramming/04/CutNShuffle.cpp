#include <iostream>

std::string cards[100];
int cardCount;

inline int GetMiddle() { return cardCount/2; }

void SwapThing(std::string& a, std::string& b)
{
    std::string temp = a;
    a = b;
    b = temp;
}

void Cut()
{
    for (int i = 0; i < cardCount/2; i++)
    {
        SwapThing(cards[i], cards[i+cardCount/2]);
        // for (int j = 0; j < cardCount; j++)
        //     std::cout << cards[j] << ' ';
        // puts("");
    }
}

void Shuffle()
{
    for (int i = cardCount/2-1; i >= 0; i--)
        SwapThing(cards[i], cards[i*2]);
}

int main()
{
    std::cin >> cardCount;

    for (int i = 0; i < cardCount; i++)
        std::cin >> cards[i];

    std::cin.ignore();

    std::string operations;
    std::getline(std::cin, operations);

    for (int i = 0; i < operations.size(); i++)
    {
        switch (operations[i])
        {
            case 'C':
                Cut();
                break;
            case 'S':
                Shuffle();
                break;
            //default doesn't exist because I want it to do nothing you fucking bitch I'm not pirate software
        }
    }

    std::cout << cards[0];
    for (int i = 1; i < cardCount; i++)
        std::cout << ' ' << cards[i];
    puts("");
}
