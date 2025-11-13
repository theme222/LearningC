#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>
#include "list.h"

#define last (((this->end()).ptr)->prev)

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  for (auto it = ls.begin(); it != ls.end(); it++)
  {
      CP::list<T> &currentList = *it;
      if (currentList.mSize == 0) continue;
      
      node* begin = currentList.begin().ptr;
      node* end = currentList.end().ptr->prev;
      
      // Detach and attach
      begin->prev = last;
      end->next = this->mHeader;
      
      last->next = begin;
      this->mHeader->prev = end;
      
      currentList.mHeader->next = currentList.mHeader;
      currentList.mHeader->prev = currentList.mHeader;
      
      // Set size
      this->mSize += currentList.mSize;
      currentList.mSize = 0;
      
  }

}

#endif
