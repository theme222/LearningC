#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct node_
{
    int start,end,weight;
} node;

node* Node(int start, int end, int weight)
{
    node *a = malloc(sizeof(node));
    a->start = start;
    a->end = end;
    a->weight = weight;
    return a;
}

for ()

int nodeArray[305][305];
int fuck[305][305];
node* toCheck[305];
int checkCount = 0;
int houseCount, checkThingIdk;



int main()
{
    scanf("%d %d", &houseCount, &checkThingIdk);
    for (int y = 0; y < houseCount; y++)
    {
        for (int x = 0; x < houseCount; x++)
        {
            scanf("%d", &fuck[y][x]);
            if (x >= y +1)
            {
                toCheck[checkCount] = Node(y,x,fuck[y][x]);
                checkCount++;
            }
        }
    }

    

    
    for (int i = 0; i < checkCount; i++)
    {
        free(toCheck[i]);
    }
    

}
