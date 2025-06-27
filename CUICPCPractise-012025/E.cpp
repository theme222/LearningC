#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> rank(2001, -1);
int input[2001];
int employeeCount;

int main()
{
    std::cin >> employeeCount;
    for (int i = 0; i < employeeCount; i++)
        std::cin >> input[i];

    for (int i = 0; i < employeeCount; i++)
    {
        for (int j = 0; j < employeeCount; j++)
        {
            int inferiorOf = input[j];
            if (inferiorOf == -1) rank[j] = 0;
            else if (rank[inferiorOf - 1] != -1) rank[j] = rank[inferiorOf - 1] + 1;
        }
    }

    int max = 0;
    for (int i = 0; i < employeeCount; i++)
        if (rank[i] > max) max = rank[i];

    printf("%d\n", max + 1);
}
