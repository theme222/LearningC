#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) { // Get size of tree
    if (n == nullptr) return 0;
    return 1 + process(n->right) + process(n->left);
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here
  if (empty()) return std::pair<KeyT,MappedT>();
  node *leftNode = mRoot->left;
  if (leftNode != nullptr) leftNode->parent = nullptr;
  node *rightNode = mRoot->right;
  if (rightNode != nullptr) rightNode->parent = nullptr;
  mRoot->left = nullptr; mRoot->right = nullptr;
  
  size_t leftNodeSize = process(leftNode);
  size_t rightNodeSize = process(rightNode);
  
  left.clear();
  right.clear();
  
  left.mRoot = leftNode;
  left.mSize = leftNodeSize;
  right.mRoot = rightNode;
  right.mSize = rightNodeSize;
  
  mSize = 1;
  return mRoot->data;
}

#endif

