#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char* convertToBase7(int num) {
    char *returnStr = malloc(sizeof(char)*10);
    char *start = returnStr;

    for (int i = 0; i < 10; i++)
        returnStr[i] = '\0';

    if (num == 0)
    {
        returnStr[0] = '0';
        return returnStr;
    }

    if (num < 0)
    {
        *start = '-';
        start++;
        num = abs(num);
    }

    int n = 9; // max based on constraints
    while (num - pow(7,n) < 0) n--;

    while (n >= 0)
    {
        int digit = num / pow(7,n);
        num -= digit*pow(7,n);
        n--;
        *start = '0' + digit;
        start++;
    }
    return returnStr;
}
