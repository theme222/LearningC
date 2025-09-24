#include <bits/stdc++.h>

std::vector<std::pair<double, std::string>> items;
std::vector<double> initialPrice;

int main()
{
    std::string id;
    double price;

    std::cin >> id;
    while (id != "END")
    {
        std::cin >> price;
        items.push_back({0, id});

        initialPrice.push_back(price);
        std::cin >> id;
    }

    while (std::cin >> id)
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].second == id)
            {
                items[i].first -= initialPrice[i];
            }
        }
    }

    std::sort(items.begin(), items.end());

    for (int i = 0; i < 3; i++)
    {
        if (i == 0 && items[i].first == 0)
        {
            std::cout << "No Sales\n";
            return 0;
        }

        if (items[i].first == 0) break;
        std::cout << items[i].second << ' ' << -items[i].first << '\n';
    }
}
