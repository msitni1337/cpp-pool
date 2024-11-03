#include "Array.hpp"

template <class T>
const char *Array<T>::IndexOutOfBoundException::what() const throw()
{
    return "Array::IndexOutOfBoundException";
}

template <class T>
Array<T>::Array() : _buff(NULL), _count(0)
{
}
template <class T>
Array<T>::Array(unsigned int count) : _count(count)
{
    _buff = new T[count];
    for (size_t i = 0; i < count; i++)
        _buff[i] = 0;
}
template <class T>
Array<T>::Array(const Array<T> &arr) : _buff(NULL), _count(arr._count)
{
    if (_count == 0)
        return;
    *this = arr;
}
template <class T>
Array<T> &Array<T>::operator=(const Array<T> &arr)
{
    delete [] _buff;
    _buff = new T[_count];
    for (size_t i = 0; i < _count; i++)
        _buff[i] = arr._buff[i];
    return *this;
}
template <class T>
Array<T>::~Array()
{
    delete [] _buff;
}
template <class T>
size_t Array<T>::size() const
{
    return _count;
}
template <class T>
T &Array<T>::operator[](unsigned int index)
{
    if (index < _count)
        return _buff[index];
    throw Array<T>::IndexOutOfBoundException();
}