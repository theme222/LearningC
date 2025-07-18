#include <iostream>
#include <ranges>

bool needsChanging[10001];

int GetCounterPart(int index, int strLen)
{
    if (strLen % 2 == 0)
    {
        if (index <= strLen/2)
            return (strLen/2+1) + (strLen/2 - index);
        else
            return (strLen/2) - (index - (strLen/2+1));
    }
    else
    {
        if (index == strLen/2+1)
            return index;
        else if (index <= strLen/2)
            return (strLen/2+1) + (strLen/2+1 - index);
        else
            return (strLen/2+1) - (index - (strLen/2+1));
    }

}

char str[10001];
int main()
{
    int strLen, initPos;
    std::cin >> strLen >> initPos;

    if (strLen == 1)
    {
        puts("0");
        return 0;
    }

    std::cin >> str;
    for (int i = strLen-1; i >= 0; i--)
        str[i+1] = str[i];

    // std::cout << str+1 << '\n';

    int counter = 0;
    int rangeStart, rangeEnd;
    if (strLen % 2 == 1 && initPos == (strLen/2)+1)
    {
        rangeStart = (strLen/2)+2;
        rangeEnd = strLen;
        initPos++;
        counter++;
    }
    else if (initPos <= strLen/2)
    {
        rangeEnd = (strLen/2);
        rangeStart = 1;
    }
    else
    {
        rangeStart = strLen/2+1;
        rangeEnd = strLen;
    }

    // for (int i = 1; i <= strLen; i++)
    //     std::cout << GetCounterPart(i, strLen) << '\n';
    // std::cout << rangeStart << ' ' << rangeEnd << '\n';

    for (int i = rangeStart; i <= rangeEnd; i++)
    {
        int j = GetCounterPart(i, strLen);
        if (str[i] != str[j])
        {
            int dist = abs(str[i] - str[j]);
            if (dist > 13)
            {
                if (i < j) dist = (str[i] - 'a') + ('z' - str[j]) + 1;
                else dist = (str[j] - 'a') + ('z' - str[i]) + 1;
            }
            counter += dist;
            needsChanging[i] = true;
            // std::cout << str[i]  << ' ' << str[j] << '\n';
        }
    }
    // std::cout << counter << std::endl;

    int changeExists = false;
    for (int i =0; i <= strLen; i++)
        changeExists = changeExists || needsChanging[i];

    if (!changeExists)
    {
        puts("0");
        return 0;
    }

    if (abs(initPos - rangeStart) < abs(initPos- rangeEnd))
    {
        int lastIndex = -1;
        for (int i = initPos; i >= rangeStart; i--)
            if (needsChanging[i]) lastIndex = i;
        counter += lastIndex != -1 ? abs(lastIndex - initPos): 0;
        for (int i = rangeEnd; i > initPos; i--)
            if (needsChanging[i])
            {
                counter += i - (lastIndex != -1? lastIndex: initPos);
                break;
            }
    }
    else
    {
        int lastIndex = -1;
        for (int i = initPos; i <= rangeEnd; i++)
            if (needsChanging[i]) lastIndex = i;
        counter += lastIndex != -1 ? abs(lastIndex - initPos): 0;
        for (int i = rangeStart; i < initPos; i++)
            if (needsChanging[i])
            {
                counter += (lastIndex != -1? lastIndex: initPos) - i;
                break;
            }
    }
    std::cout << counter << std::endl;
}
