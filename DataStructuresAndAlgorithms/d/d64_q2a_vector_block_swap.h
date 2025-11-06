#ifndef __STUDENT_H_
#define __STUDENT_H_

#define isValid(iter) (this->begin() <= (iter) && (iter) < this->end())

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
    if (m == 0) return false;
    if (a > b) std::swap(a, b);
    iterator endA = a + m-1;
    iterator endB = b + m-1;
    
    if (
        !isValid(a) ||
        !isValid(b) ||
        !isValid(endA) ||
        !isValid(endB)
    ) return false;
    
    if (a == b) return false;
    if (b - endA <= 0) return false; 
    
    for (int i = 0; i < m; i++)
        std::swap(a[i], b[i]);
    return true;
}

#endif
