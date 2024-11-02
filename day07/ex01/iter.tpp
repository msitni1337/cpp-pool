#include "iter.hpp"

template<class T> void iter(T* arr, unsigned long count, void (*f)(T&))
{
    for (size_t i = 0; i < count; i++)
        f(arr[i]);        
}
