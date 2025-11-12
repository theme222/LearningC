void replace(const T& x, list<T>& y) {

    for (auto it = this->begin(); it != this->end();)
    {
        node* before = it.ptr->prev; 
        node* after = it.ptr->next; 
        
        if (*it == x)
        {
            auto newIt = y.begin();
            
            if (newIt == y.end())
            {
                it = this->erase(it);
                continue;
            }
            
            node* first = new node(newIt.ptr->data, before, NULL);
            before->next = first;
            
            node* prev = first;
            node* current = prev; // incase y has 1 value
            
            for (newIt++; newIt != y.end(); newIt++)
            {
                current = new node(newIt.ptr->data, prev, NULL);
                prev->next = current;
                prev = current;
            }
            
            node* last = current;
            last->next = after;
            
            after->prev = last;
            node* toDelete = it.ptr;
            
            it.ptr = after;
            delete toDelete;
            
            mSize += y.size()-1;
            continue;
        }
        
        it++;
    }

}