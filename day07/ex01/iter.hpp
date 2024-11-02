#pragma once
#include <cstddef>

template<class T> void iter(T*, unsigned long, void (*f)(T&));