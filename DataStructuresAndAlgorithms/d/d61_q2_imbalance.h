////// ////// ////// //////

// Your code here

int maxImbalance;
KeyT minT; // This will always have a valid value because maxImbalance is set to -1 making imb > maxImbalance always true first

int getImbalance(node *n) // returns height
{
    if (n == nullptr) return -1;
    int heightLeft = getImbalance(n->left);
    int heightRight = getImbalance(n->right);
    
    int imb = abs(heightLeft-heightRight);
    if (imb > maxImbalance) 
    {
        maxImbalance = imb;
        minT = n->data.first;
    }
    else if (imb == maxImbalance && mLess(n->data.first, minT))
        minT = n->data.first;
    
    return std::max(heightLeft, heightRight) + 1;
}

KeyT getValueOfMostImbalanceNode() {
    maxImbalance = -1;
    
    getImbalance(mRoot);
    return minT;
}
////// ////// ////// //////
