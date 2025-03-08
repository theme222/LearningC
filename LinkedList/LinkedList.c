#include "LinkedList.h"

void InitializeLinkedList(LinkedList **LL, char* text)
{
    *LL = malloc(sizeof(LinkedList));
    (*LL)->text = text;
    (*LL)->child = NULL;
    (*LL)->parent = NULL;
}

void AppendLinkedList(LinkedList *LL, char* text)
{
    LinkedList *currentLL = LL;
    LinkedList *childLL;
    InitializeLinkedList(&childLL, text);
    while (currentLL->child != NULL)
    {
        currentLL = currentLL->child;
    }
    currentLL->child = childLL;
    childLL->parent = currentLL;
}

void FreeNode(LinkedList *LL)
{
    free(LL->text);
    free(LL);
}

void FreeLinkedList(LinkedList *LL)
{
    if (LL == NULL) return;
    FreeLinkedList(LL->child);
    FreeNode(LL);
}

void PrintLinkedList(LinkedList *LL)
{
    while (LL != NULL)
    {
        puts(LL->text);
        LL = LL->child;
    }
}

void RemoveNode(LinkedList *LL)
{
    LinkedList *parentLL = LL->parent;
    LinkedList *childLL = LL->child;
    if (childLL != NULL && parentLL != NULL)
    {
        parentLL->child = childLL;
        childLL->parent = parentLL;
    }
    else if (childLL == NULL)
    {
        parentLL->child = NULL;
    }
    else if (parentLL == NULL)
    {
        childLL->parent = NULL;
    }
    FreeNode(LL);
}

