#pragma once
#include <cstddef>

template<typename T> void iter(T* arr, unsigned long count, void (*f)(T&));
template<typename T> void iter(const T* arr, unsigned long count, void (*f)(const T&));