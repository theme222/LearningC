#include <iostream>
#include <algorithm>

std::string operator*(const std::string& str, const int a)
{
    std::string returnStr = "";
    for (int i =0; i < a; i++)
        returnStr += str;

    return returnStr;
}

void ZeroOut(std::string &str, int index)
{
    for (unsigned int i = index; i < str.size(); i++)
        str[i] = '0';
}

void IncrementString(std::string &str, int index)
{
    if (str[index] == '9')
    {
        str[index] = '0';
        IncrementString(str, index-1);
    }
    else
        str[index]++;
}

std::pair<int, int> GetBaseUnit(std::string &str)
{
    std::pair<int, int> pair;
    for (unsigned int i = 0; i < str.size();i++)
    {
        if (str[i] - '0' == 0) continue;
        pair.first = str[i] - '0';
        pair.second = i;
        return pair;
    }
    pair.first = 0;
    pair.second = str.size() - 1;
    return pair;
}

void GetNextCroissaria(std::string &str, int startPos)
{
    bool setZero = false;
    for (unsigned int i = startPos + 1; i < str.size(); i++)
    {
        if (str[startPos] <= str[i] && !setZero)
        {
            IncrementString(str, i-1);
            setZero = true;
        }
        if (setZero) str[i] = '0';
    }
}


int main()
{
    int count;
    std::cin >> count;

    while (count--)
    {
        std::string L, R;
        std::cin >> L >> R;

        int sizeDif = R.size() - L.size();

        // Set sizes to be the same
        L = ((std::string)"0" * (R.size() - L.size())) + L;

        // Transform L to be the lowest possible Croissaria number
        GetNextCroissaria(L, sizeDif);

        int total = 0;
        auto base = GetBaseUnit(L);
        for (int i = base.second; i >= 0; i--)
        {
            while (L[i] != '0' && (i != 0 || L[0] <= R[0]))
            {
                int unitTotal = 1;
                for (unsigned int j = i+1; j < L.size(); j++)
                {
                    int first = std::min(base.first, (L[0] == R[0] ? R[j] - '0' + 1: base.first));
                    int thing = first - (L[j] - '0');
                    unitTotal *= thing;
                }

                total += unitTotal;
                IncrementString(L, i);
                GetNextCroissaria(L, GetBaseUnit(L).second);
                base = GetBaseUnit(L);
            }
        }

        std::cout << total <<  std::endl;

    }
}
