#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int things[10];
int countPoints(char* rings) {
    for (int i =0; i < 10; i++)
    {
        things[i] = 0;
    }
    int length = strlen(rings);

    for (int i = 0; i < length; i+=2)
    {
        char color = rings[i];
        int num = rings[i+1] - '0';

        switch (color)
        {
            case 'R':
                things[num] |= 1;
                break;
            case 'G':
                things[num] |= 2;
                break;
            case 'B':
                things[num] |= 4;
                break;
        }
    }

    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if( things[i] == 7) count++;
    }

    return count;
}
