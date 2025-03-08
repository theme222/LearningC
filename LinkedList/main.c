#include "LinkedList.h"

int main()
{
    LinkedList *LL;
    InitializeLinkedList(&LL, strdup("parent of all parents"));

    for (int i= 0; i < 4; i++)
    {
        char str[10] = "child";
        str[5] = '0' + i;
        str[6] = '\0';
        AppendLinkedList(LL, strdup(str));
    }

    puts("Hello darkness my old friend");
    PrintLinkedList(LL);
    RemoveNode(LL->child->child);
    PrintLinkedList(LL);
    FreeLinkedList(LL);

}
    
    