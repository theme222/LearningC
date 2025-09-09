#include <iostream>
#include <cmath>
#include <queue> // Haha just kidding

std::vector<int> queueTime;
int counter_new, counter_next, counter_start, totalTime, totalOrdered, currentNextId = -1;

int main()
{
    int actions;
    std::cin >> actions;

    std::string a;
    std::cin >> a;
    std::cin >> counter_new;
    actions--;

    counter_next = counter_start = counter_new; // I hated this syntax but honestly? Its pretty good
    queueTime.reserve(counter_start);
    while (actions--)
    {
        std::string action;
        int num;
        std::cin >> action;
        if (action != "next" && action != "avg_qtime") std::cin >> num;

        if (action == "new")
        {
            queueTime.push_back(num);
            printf(">> ticket %d\n", counter_new);
            counter_new++;
        }
        else if (action == "next")
        {
            currentNextId = counter_next;
            counter_next++;
            printf(">> call %d\n", currentNextId);
        }
        else if (action == "order")
        {
            totalTime += num - queueTime[currentNextId - counter_start];
            totalOrdered++;
            printf(">> qtime %d %d\n", currentNextId, num - queueTime[currentNextId - counter_start]);
        }
        else if (action == "avg_qtime")
        {
            std::cout << ">> avg_qtime " << round(((double)totalTime / (double)totalOrdered) * 100) / 100 << '\n';
        }
    }

}
