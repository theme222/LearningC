#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "list.h"

template <typename T>
void CP::list<T>::zigzag(CP::list<T> &ls) {
    bool isCurrent = true;
    
    node* current = mHeader->next->next;
    node* lsIt = ls.mHeader->next;
    while (lsIt != ls.mHeader)
    {
        node* prev = current->prev;
        node *temp = lsIt->next;
        
        prev->next = lsIt;
        lsIt->prev = prev;
        current->prev = lsIt;
        lsIt->next = current;
        
        if (current != this->mHeader)
            current = current->next;
        
        lsIt = temp;
    }
    
    this->mSize += ls.mSize;
    ls.mHeader->next = ls.mHeader;
    ls.mHeader->prev = ls.mHeader;
    ls.mSize = 0;
}

#endif
