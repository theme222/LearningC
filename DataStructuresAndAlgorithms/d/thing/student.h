#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "map_bst.h"
#include <algorithm>


template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
    
    CP::map_bst<KeyT,MappedT,CompareT> result;
    if (empty()) return result;
    
    node* T1 = mRoot; // normal tree
    node* T2 = nullptr; // new tree
    
    if (compare(mRoot->data.first, val) > -1) std::swap(T1, T2);
    
    node* currentNode = mRoot;
    int currentMode; 
    while (true)
    {
        if (currentMode == 0)
            break;
        if (currentMode == -1) // current more
        {
            currentMode = compare(val, mRoot->data.first);
            
        }
        
        
    }
    
    
    
    
    return result;
}

#endif
