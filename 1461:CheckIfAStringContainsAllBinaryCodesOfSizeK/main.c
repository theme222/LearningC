#include <stdbool.h>
#include <string.h>
#include <math.h>

bool binValues[1048576];

int stringToIntBinary(char* start, char *end)
{
    int val = 0;
    for (char *a = end; a >= start; a--)
        val += (*a - '0') * pow(2, (int)(end-a));
    return val;
}


bool hasAllCodes(char* s, int k) {
    int length = strlen(s);
    for (int i = 0; i < pow(2,k); i++)
        binValues[i] = false;

    int diff = k-1;
    for (int j = 0; j < length - diff; j++)
        binValues[stringToIntBinary(s+j, s+j+diff)] = true;

    for (int i = 0; i < pow(2, k); i++)
        if (binValues[i] == false) return false;

    return true;
}
