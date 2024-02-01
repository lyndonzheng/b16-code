#ifndef __array_delete__
#define __array_delete__

#include <cstddef>
#include <utility>
#include <vector>

template <typename T>
void array_delete(std::vector<T> &A, std::size_t index)
{
    // WRITE YOUR CODE HERE
    if (index < A.size()) {
        // Erase the element at the given index
        A.erase(A.begin() + index);
    }
}

#endif // __array_delete__
