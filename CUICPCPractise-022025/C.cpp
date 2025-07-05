#include <iostream>

int arr[30][30];
int main()
{
    int n;
    std::string notGonnaUseCharArrLol;
    std::cin >> n;
    std::cin >> notGonnaUseCharArrLol;

    for (int i = 0; i < n-1; i++)
        arr[notGonnaUseCharArrLol[i] - 'A'][notGonnaUseCharArrLol[i+1] - 'A']++;

    int maxI = 0, maxJ = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (arr[i][j] > arr[maxI][maxJ])
            {
                maxI = i;
                maxJ = j;
            }
        }
    }

    printf("%c%c\n", maxI + 'A', maxJ + 'A');
}
