#include "easyfind.hpp"

template<class T, class it> it easyfind(T arr, int num)
{
    return std::find(arr.begin(), arr.end(), num);
}