#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <set>
#include "queue.h"

#define trueIndex(idx) ((this->mFront + idx) % this->mCap)

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
    std::set<size_t> posToDelete(pos.begin(), pos.end()); // maybe?
    size_t newPos = 0, oldPos = 0;
    
    while (oldPos < mSize)
    {
        if (posToDelete.count(oldPos) == 0) 
        {
            mData[trueIndex(newPos)] = mData[trueIndex(oldPos)];
            newPos++;
        }
        oldPos++;
    }
    
    mSize -= pos.size();
}

#endif
