#include "iter.hpp"

template<typename T> void iter(T* arr, unsigned long count, void (*f)(T&))
{
    for (size_t i = 0; i < count; i++)
        f(arr[i]);
}

template<typename T> void iter(const T* arr, unsigned long count, void (*f)(const T&))
{
    for (size_t i = 0; i < count; i++)
        f(arr[i]);
}