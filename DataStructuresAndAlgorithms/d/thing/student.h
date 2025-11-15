#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
    //your code here
    CP::map_bst<KeyT,MappedT,CompareT> result;

    node *T1 = nullptr; // The original one
    node *T2 = nullptr; // The one in result

    node *curNode = this->mRoot;
    int prevMode = -2;
    bool isFirst = true;

    while (true)
    {
        if (curNode == nullptr) break;

        int currentMode = compare(val, curNode->data.first);
        if (currentMode == prevMode)
        {
            curNode = currentMode == -1 ? curNode->left : curNode->right;
            prevMode = currentMode;
            continue;
        }

        if (currentMode == 0) // val == current : add left tree to T1 and add current and right tree into T2
        {
            // Detach left tree
            node *leftTree = curNode->left;
            if (leftTree != nullptr) leftTree->parent = nullptr;

            curNode->left = nullptr;
            child_link(curNode->parent, curNode->data.first) = nullptr; // set parent of curnode 's child to be null
            curNode->parent = nullptr;

            if (leftTree != nullptr)
            {
                if (T1 == nullptr) T1 = leftTree;
                else
                {
                    // Get the parent
                    node *parent;
                    find_node(leftTree->data.first, T1, parent);

                    child_link(parent, leftTree->data.first) = leftTree;

                    leftTree->parent = parent;
                }
            }

            if (T2 == nullptr) T2 = curNode;
            else
            {
                // Get the parent
                node *parent;
                find_node(curNode->data.first, T2, parent);

                // Set parent child as curNode
                child_link(parent, curNode->data.first) = curNode;

                curNode->parent = parent;
            }

            break;
        }
        else if (currentMode == -1) // val < current : place current and its right tree into T2
        {
            // detach newNode
            node *newNode = curNode->left;
            if (!isFirst)
            {
                curNode->left = nullptr;
                if (newNode != nullptr) newNode->parent = nullptr;
            }


            child_link(curNode->parent, curNode->data.first) = nullptr; // set parent of curnode 's child to be null
            curNode->parent = nullptr;

            if (T2 == nullptr) T2 = curNode;
            else
            {
                // Get the parent
                node *parent;
                find_node(curNode->data.first, T2, parent);

                // Set parent child as curNode
                child_link(parent, curNode->data.first) = curNode;

                curNode->parent = parent;
            }

            curNode = newNode;
        }
        else if (currentMode == 1) // val > current : place current and left tree into T1
        {
            // detach newNode
            node *newNode = curNode->right;
            if (!isFirst)
            {
                curNode->right = nullptr;
                if (newNode != nullptr) newNode->parent = nullptr;
            }

            child_link(curNode->parent, curNode->data.first) = nullptr; // set parent of curnode 's child to be null
            curNode->parent = nullptr;

            if (T1 == nullptr) T1 = curNode;
            else
            {
                // Get the parent
                node *parent;
                find_node(curNode->data.first, T1, parent);

                // Set parent child as curNode
                child_link(parent, curNode->data.first) = curNode;

                curNode->parent = parent;
            }

            curNode = newNode;
        }

        prevMode = currentMode;
        isFirst = false;
    }

    result.mRoot = T2;
    this->mRoot = T1;

    return result;
}

#endif
