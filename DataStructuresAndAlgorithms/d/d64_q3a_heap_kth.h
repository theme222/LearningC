#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

#define leftChild(a) (a*2)+1
#define rightChild(a) (a*2)+2
#define parent(a) (a-1)/2

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
    switch(k)
    {
        case 1:
            return mData[0];
        case 2:
            if (mLess(mData[1], mData[2])) return mData[2];
            else return mData[1];
        case 3:
        {
            int secondMax = 1;
            int sibling = 2;
            if (mLess(mData[1], mData[2])) {
                secondMax = 2;  
                sibling = 1;
            } 
            
            int thirdMax = sibling;
            int lChild = leftChild(secondMax);
            int rChild = rightChild(secondMax);
            
            if (lChild < mSize && mLess(mData[thirdMax],mData[lChild])) thirdMax = lChild;
            if (rChild < mSize && mLess(mData[thirdMax],mData[rChild])) thirdMax = rChild;
            
            return mData[thirdMax];
        }
        default: exit(1);
    }
}

#endif
