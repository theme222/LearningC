#include <iostream>
#include <stdexcept>

std::string codes[100];
int costs[100];
int countryCount;

int GetCost(std::string& code)
{
    for (int i = 0; i < countryCount; i++)
        if (codes[i] == code) return costs[i];
    throw std::runtime_error("Could not find code " + code);
}

int main()
{
    std::cin >> countryCount;

    for (int i = 0; i < countryCount; i++)
        std::cin >> codes[i] >> costs[i];

    std::cin.ignore();
    std::string travelPlan;
    std::getline(std::cin, travelPlan);

    int totalCost = 0;
    std::string currCode = travelPlan.substr(4, 2);
    for (int i = 11; i < travelPlan.size(); i+=7)
    {
        if (travelPlan.substr(i, 2) == currCode) continue;
        currCode = travelPlan.substr(i, 2);
        totalCost += GetCost(currCode);
    }

    std::cout << totalCost << std::endl;
}
