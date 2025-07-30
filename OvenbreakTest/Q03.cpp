#include <iostream>
#include <map>
#include <algorithm>

typedef std::pair<int,char> card; // Rank Suit
typedef std::vector<int> intArr;
card hand[5];

int stringToIntThing(std::string a)
{
    if (a == "K") return 13;
    else if (a == "Q") return 12;
    else if (a == "J") return 11;
    else if (a == "A") return 1;
    else return std::stoi(a);
}

bool IsSameSuit()
{
    char currentSuit = hand[0].second;
    for (int i =1; i < 5; i++)
        if (hand[i].second != currentSuit) return false;
    return true;

}

void NormalizeAce()
{
    for (int i = 0 ; i < 5; i++)
        if (hand[i].first == 14) hand[i].first = 1;
}

std::vector<int> CountCardOcurrences()
{
    NormalizeAce();
    std::vector<int> rankToCount(15,0);
    for (int i = 0; i < 5; i++)
        rankToCount[hand[i].first]++;
    
    return rankToCount;
}

bool IsInOrder()
{
    int ranks[5];
    for (int i = 0; i < 5; i++)
        ranks[i] = hand[i].first;
    
    std::sort(ranks, ranks+5);

    bool notHighAce = true;
    for (int i =1; i < 5;i++)
    {
        if (ranks[i] - 1 != ranks[i-1]) 
        {
            notHighAce = false;
            break;
        }
    }

    for (int i = 0; i < 5; i++)
        if (ranks[i] == 1) ranks[i] = 14;
    
    bool highAce = true;
    std::sort(ranks, ranks+5);
    for (int i =1; i < 5;i++)
    {
        if (ranks[i] - 1 != ranks[i-1]) 
        {
            highAce = false;
            break;
        }
    }
    return notHighAce || highAce;
}

bool RoyalFlush()
{
    if (! IsSameSuit()) return false;
    if (! IsInOrder()) return false;
    bool hasAce = false;
    bool hasKing = false;
    for (int i =0; i < 5; i++)
    {
        if (hand[i].first == 14 || hand[i].first == 1) hasAce = true; 
        if (hand[i].first == 13) hasKing = true;
    }

    return hasAce && hasKing;
}

bool StraightFlush()
{
    if (! IsSameSuit()) return false;
    if (! IsInOrder()) return false;
    return true;
}

bool QUAAAAAD()
{
    std::vector<int> rankToCount = CountCardOcurrences();
    for (int i = 1; i <= 14; i++)
        if (rankToCount[i] == 4) return true; 
    return false;
}

bool FullHouse()
{
    intArr rank = CountCardOcurrences();
    bool hasTwo = false;
    bool hasThree = false;
    for (int i =1; i <= 14; i++)
    {
        if (rank[i] == 2) hasTwo = true;
        if (rank[i] == 3) hasThree = true;
    }
    return hasTwo && hasThree;
}

bool FlushingMyToiletAt3AMGoneWrong()
{
    return IsSameSuit();
}

bool Straight()
{
    return IsInOrder();
}

bool Trips()
{
    intArr rankToCount = CountCardOcurrences();
    for (int i = 1; i <= 14; i++)
        if (rankToCount[i] == 3) return true;
    return false;
}

bool TwoPair()
{
    intArr rankToCount = CountCardOcurrences();
    int pairCount = 0;
    for (int i = 1; i <= 14; i++)
        if (rankToCount[i] == 2) pairCount++;
    return pairCount == 2;
}

bool PocketACESSSSS()
{
    intArr rankToCount = CountCardOcurrences();
    for (int i = 1; i <= 14; i++)
        if (rankToCount[i] == 2) return true;
    return false;
}

bool HigherThanMtEverest()
{
    return true; //uhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
}


int main()
{
    for (int i = 0; i < 5; i++)
    {
        std::string a;
        char b;
        std::cin >> a >> b;
        card c = {stringToIntThing(a), b};
        hand[i] = c;
    }

    if (RoyalFlush())
        puts("royal flush");
    else if (StraightFlush())
        puts("straight flush");
    else if (QUAAAAAD())
        puts("four of a kind");
    else if (FullHouse())
        puts("full house");
    else if (FlushingMyToiletAt3AMGoneWrong())
        puts("flush");
    else if (Straight())
        puts("straight");
    else if (Trips())
        puts("three of a kind");
    else if (TwoPair())
        puts("two pair");
    else if (PocketACESSSSS())
        puts("pair");
    else if (HigherThanMtEverest())
        puts("high card");
}