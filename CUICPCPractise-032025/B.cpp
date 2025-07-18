#include <iostream>

int counter[26];
int howManyToPrint[26];
int main()
{
    int goalSize;
    std::string str;
    std::cin >> goalSize >> str;

    for (int i = 0; i < str.size(); i++)
        counter[str[i]-'a']++;

    for (int i = 0; i < 26; i++)
    {
        if (counter[i] != 0 && counter[i] % goalSize != 0)
        {
            puts("-1");
            exit(0);
        }
        howManyToPrint[i] = counter[i] / goalSize;
    }

    for (int i = 0; i < goalSize; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (counter[j] > 0)
            {
                for (int k = 0; k < howManyToPrint[j]; k++) printf("%c", j+'a');
            }
        }
    }
    puts("");
}
