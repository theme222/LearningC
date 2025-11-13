#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
    if (ptr == NULL) return 0;
    int total = 0;
    
    if (ptr->left != NULL) total += process(ptr->left);
    if (ptr->right != NULL) total += process(ptr->right);
    
    if ((ptr->left == NULL || ptr->right == NULL) && !(ptr->left == NULL && ptr->right == NULL))
        return 1 + total;
    else 
        return total;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
    return process(this->mRoot);
}

#endif
