#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>
#include "queue.h"

int getIndex(int idx, int front, int size, int cap)
{
    while (idx < 0) idx += size;
    return (idx + front) % cap;
}

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
    while (a < b)
    {
        std::swap(mData[getIndex(a, mFront, mSize, mCap)], mData[getIndex(b, mFront, mSize, mCap)]);
        a++;
        b--;
    }
}

#endif
