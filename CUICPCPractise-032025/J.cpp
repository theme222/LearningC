#include <iostream>
#include <vector>

std::string nameList[101];
int requiredHighLow[27][27];
bool indexIsFullyChecked[101];

std::string customAlph = "abcdefghijklmnopqrstuvwxyz";

int findInAlph(const char c)
{
    for (int i =0; i < 26; i++)
        if (customAlph[i] == c) return i;
    exit(1);
    return -1;
}

void ImpossibleExit()
{
    puts("Impossible");
    exit(0);
}

int GetIntChar(const std::string& str, int charPos)
{
    return str[charPos] -'a';
}

void RemoveIndex(std::string& str, int index)
{
    for (int i = index; i < str.size()-1; i++)
        str[i] = str[i+1];
    str.resize(26);
}


int main()
{
    int nameCount;
    std::cin >> nameCount;

    for (int i = 0; i <nameCount; i++)
        std::cin >> nameList[i];

    // std::cout << GetIntChar(std::string("asdfgh"), 2) << std::endl;
    for (int c = 0; c < 100; c++)
    {
        // puts("asdfasdfasdf");
        // std::cout << c << '\n';
        // for (int i = 0; i < nameCount; i++)
        //     if (indexIsFullyChecked[i])
        //         std::cout << nameList[i] << ' ';


        std::vector<int> charHasBeenUsed(27, 0);
        for (int i = 0; i < nameCount; i++)
        {
            if (indexIsFullyChecked[i]) continue;
            if (nameList[i].size() > c) charHasBeenUsed[GetIntChar(nameList[i],c)]++;

            if (i == 0) continue;
            if (nameList[i-1].size() <= c) continue;
            if (nameList[i].size() <= c) ImpossibleExit();
            int currentCharInt  = GetIntChar(nameList[i],c);
            int lastCharInt = GetIntChar(nameList[i-1], c);
            if (lastCharInt != GetIntChar(nameList[i], c))
            {
                if (requiredHighLow[lastCharInt][currentCharInt] == -1) ImpossibleExit();
                requiredHighLow[lastCharInt][currentCharInt] = 1;
                requiredHighLow[currentCharInt][lastCharInt] = -1;
            }
        }

        for (int i = 0; i < nameCount; i++)
            if (c < nameList[i].size() && charHasBeenUsed[GetIntChar(nameList[i], c)] == 1) indexIsFullyChecked[i] = true;
    }

    // for (int i = 0; i < 26; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //     {
    //         std::cout << requiredHighLow[i][j];
    //     }
    //     puts("");
    // }


    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            for (int c = j-1; c >= 0; c--)
            {
                if (requiredHighLow[customAlph[j] - 'a'][customAlph[c] - 'a'] == 1)
                {
                    customAlph = customAlph.substr(0,c) + customAlph[j] + customAlph.substr(c);
                    RemoveIndex(customAlph, j+1);
                    break;
                }
            }
        }
    }
    std::cout << customAlph << std::endl;
}
