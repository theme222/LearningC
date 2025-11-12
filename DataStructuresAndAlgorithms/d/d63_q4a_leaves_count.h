#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count(node* n) {
    size_t totalLeaves = 0;
    if (n->left != nullptr) totalLeaves += leaves_count(n->left);
    if (n->right != nullptr) totalLeaves += leaves_count(n->right);
    if (n->left == nullptr && n->right == nullptr) totalLeaves++;
    return totalLeaves;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count() {
  return leaves_count(mRoot);
  //write your code here
}


#endif
