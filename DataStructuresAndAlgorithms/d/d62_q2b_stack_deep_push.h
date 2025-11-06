// d62_q2b_stack_deep_push

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stack>

template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
    
    std::stack<T> stupid;
    for (int i = 0; i < pos; i++)
    {
        stupid.push(this->top());
        this->pop();
    }
    
    this->push(value);
    
    for (int i = 0; i < pos; i++)
    {
        this->push(stupid.top());
        stupid.pop();
    }
}
#endif
