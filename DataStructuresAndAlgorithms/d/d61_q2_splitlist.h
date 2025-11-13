/////// /////// /////// ///////

int dist(node* a, node* b)
{
    int d = 0;
    while(a != b)
    {
        d++;
        a = a->next;
    }
    return d;
}

void splitList(list<T>& list1, list<T>& list2) {
    if (mSize == 0) return;
    
    // Add your code here
    int mid = (mSize - 1)/2;
    
    // Get first second start end
    node *firstStart, *firstEnd, *secondStart, *secondEnd;
    firstEnd = firstStart = begin().ptr;
    secondEnd = end().ptr->prev;
    
    while (mid--) firstEnd = firstEnd->next;
    secondStart = firstEnd->next; 
    
    // detach and attach
    firstStart->prev = list1.mHeader->prev;
    firstEnd->next = list1.mHeader;
    
    list1.mHeader->prev->next = firstStart;
    list1.mHeader->prev = firstEnd;
    
    if (secondStart != mHeader)
    {
        secondStart->prev = list2.mHeader->prev;
        secondEnd->next = list2.mHeader;
        
        list2.mHeader->prev->next = secondStart;
        list2.mHeader->prev = secondEnd;
    }
    
    // set size
        
    int firstDist = dist(firstStart, firstEnd);
    list1.mSize += firstDist + 1;
    
    if (secondStart != mHeader) 
    {
        int secondDist = dist(secondStart, secondEnd);
        list2.mSize += secondDist + 1;
    }
    
    this->mSize = 0;
    this->mHeader->next = mHeader;
    this->mHeader->prev = mHeader;
}

/////// /////// /////// ///////
