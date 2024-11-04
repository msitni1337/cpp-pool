#include "easyfind.hpp"
#include <iostream>

template <class T, class it>
it easyfind(T arr, int num)
{
    it s = std::find(arr.begin(), arr.end(), num);
    if (s == arr.end())
        std::cout << "Number not found.\n";
    else
        std::cout << "Number is found: " << *s << '\n';
    return s;
}