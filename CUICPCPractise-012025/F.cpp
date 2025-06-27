#include <iostream>
#include <cmath>
#include <cstdint>
#include <vector>

// Min h / n Max h - n

void removeIndex(std::vector<uint64_t>& vec, std::vector<uint64_t>& toRemove)
{
    for (int index = toRemove.size() - 1; index >= 0; index--)
    {
        for (int i = toRemove[index] + 1; i < vec.size(); i++)
            vec[i-1] = vec[i];

        vec.resize(vec.size()-1);
    }
}

void IncrementTrueDamage(std::vector<uint64_t>& poisonTimes, uint64_t k, uint64_t& trueDamage, uint64_t health)
{
    // Increment True damage
    std::vector<uint64_t> toRemove;
    for (int i = 0; i < poisonTimes.size() - 1; i++)
    {
        if (poisonTimes[i] + k >= poisonTimes[i+1])
        {
            trueDamage += poisonTimes[i+1] - poisonTimes[i];
            toRemove.push_back(i);
        }
    }

    removeIndex(poisonTimes, toRemove);
}


int main()
{
    int tests;
    std::cin >> tests;

    while (tests--)
    {
        uint64_t attacks, health;
        std::cin >> attacks >> health;
        std::vector<uint64_t> poisonTimes(attacks);

        for (int i = 0; i < attacks; i++)
            std::cin >> poisonTimes[i];

        if (attacks == 1)
        {
            std::cout << health << '\n';
            continue;
        }

        uint64_t trueDamage = 0;
        while (true)
        {
            uint64_t diff = 1e12;
            // Find the lowest diff
            for (int i = 1; i < poisonTimes.size(); i++)
            {
                if (poisonTimes[i] - poisonTimes[i-1] < diff)
                    diff = poisonTimes[i] - poisonTimes[i-1];
            }

            double currentK = (double)(health - trueDamage) / (double)poisonTimes.size();
            if (poisonTimes.size() == 1 || currentK <= diff)
            {
                printf("%lu\n", (uint64_t)round(currentK));
                break;
            }

            IncrementTrueDamage(poisonTimes, currentK, trueDamage, health);
        }

    }
}
