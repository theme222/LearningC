#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedList
{
    int id;
    char *text;
    struct LinkedList *child;
    struct LinkedList *parent;
} LinkedList;

// Function declarations
void InitializeLinkedList(LinkedList **LL, char *text);
void AppendLinkedList(LinkedList *LL, char *text);
void FreeNode(LinkedList *LL);
void FreeLinkedList(LinkedList *LL);
void PrintLinkedList(LinkedList *LL);
void RemoveNode(LinkedList *LL);

#endif // LINKEDLIST_H
