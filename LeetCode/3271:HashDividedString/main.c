#include <stdint.h>
#include <stdio.h>

char result[1000];
char* stringHash(char* s, int k) {
    for (int i = 0; i < 1000; i++)
        result[i] = '\0';

    int totalLength = 0;

    int currentSum = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        currentSum += s[i] - 97;
        if ((i + 1) % k == 0)
        {
            result[totalLength] = (char)(currentSum % 26 + 97);
            totalLength++;
            currentSum = 0;
        }
    }

    return result;
}

int main()
{
    stringHash("abcd", 2);
    printf("%s\n", result);
}
