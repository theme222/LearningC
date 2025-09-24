#include <iostream>
#include <algorithm>
#include <vector>

int currentNum, num, index, previousIndex, count = 1;
std::vector<std::tuple<int, int, int>> ranges;

int getRange(std::tuple<int, int, int> tup)
{
    return std::get<2>(tup) - std::get<1>(tup);
}

bool customSort(std::tuple<int, int, int> tup1, std::tuple<int, int, int> tup2)
{
    int num1 = std::get<0>(tup1);
    int num2 = std::get<0>(tup2);

    int start1 = std::get<1>(tup1);
    int start2 = std::get<1>(tup2);

    int end1 = std::get<2>(tup1);
    int end2 = std::get<2>(tup2);

    int range1 = end1 - start1;
    int range2 = end2 - start2;

    if (range2 == range1)
    {
        if (num1 == num2)
        {
            return start1 < start2;
        }
        else return num1 < num2;
    }
    else return range1 > range2;
}

int main()
{
    std::cin >> num;
    currentNum = num;

    while (std::cin >> num)
    {
        if (num == currentNum)
            count++;
        else
        {
            ranges.push_back(std::tuple(currentNum, previousIndex, index+1));
            previousIndex = index + 1;
            currentNum = num;
            count = 1;
        }
        index++;
    }

    ranges.push_back(std::tuple(currentNum, previousIndex, index+1));
    std::sort(ranges.begin(), std::end(ranges), customSort);

    using std::get;
    int currSize = getRange(ranges[0]);
    printf("%d --> x[ %d : %d ]\n", get<0>(ranges[0]), get<1>(ranges[0]), get<2>(ranges[0]));
    for (int i = 1; i < ranges.size(); i++)
    {
        if (getRange(ranges[i]) != currSize) break;
        printf("%d --> x[ %d : %d ]\n", get<0>(ranges[i]), get<1>(ranges[i]), get<2>(ranges[i]));
    }

}
