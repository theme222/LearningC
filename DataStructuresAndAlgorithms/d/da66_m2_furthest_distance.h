#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"
#define setmax(val) if ((val) > aux) aux = (val)


template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){ // aux is total depth
	// You MAY use this function
	if (n == NULL)  
	{
	    setmax(-1);
		return 0;
	}
	if (n->left == NULL && n->right == NULL) 
	{
	    setmax(0);
    	return 1; // is leaf
	}
	
	int left = my_recur(n->left, aux);
	int right = my_recur(n->right, aux);
	
	setmax(left + right);
	return std::max(left, right) + 1; // return depth of up to this node
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
    int maximum = -2;
    my_recur(mRoot, maximum);
    return maximum;
}

#endif
