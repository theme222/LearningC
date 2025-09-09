#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<double, std::string> numandname;

int sortthingyay(numandname a, numandname b)
{
    return a.first > b.first;
}

std::vector<numandname> list;
std::vector<numandname> haha_list;
std::vector<numandname> frac_list;

void PrintVector(std::vector<numandname> v)
{
    for (auto a : v)
        std::cout << a.first << ' ' << a.second << '\n';
}

int main()
{
    std::string currentName;
    int votes;

    while (std::cin >> currentName)
    {
        if (currentName == "END") break;
        std::cin >> votes;
        list.push_back(std::pair((double)votes, currentName));
    }
    haha_list = list; // save this shit for later

    double totalVotes = 0;
    for (numandname& n: list)
        totalVotes += n.first;

    for (numandname& n: list)
        n.first /= totalVotes / 100;

    frac_list = list; // Copy all values over

    // PrintVector(list);

    for (int i = 0; i < list.size(); i++)
    {
        list[i].first = (int)list[i].first;
        frac_list[i].first -= (int)frac_list[i].first;
    }


    // Turn it into death destroyer of worlds????????
    std::sort(frac_list.begin(), frac_list.end(), sortthingyay);

    // Get total people
    int total = 0;
    for (numandname& n: list)
        total += n.first;

    // std::cout << total << std::endl;
    for (int i = 0; i < (100-total); i++)
    {
        std::string nameToFind = frac_list[i].second;
        for (numandname& n: list)
        {
            if (n.second == nameToFind)
            {
                n.first++;
            }
        }
    }

    std::sort(haha_list.begin(), haha_list.end(), sortthingyay);
    for (numandname& n: haha_list)
    {
        int people;
        for (numandname& b: list)
            if (b.second == n.second)
                people = (int)b.first;

        if (people == 0) break;
        std::cout << n.second << ' ' << people << ' ' << (int)n.first << std::endl;
    }
}
