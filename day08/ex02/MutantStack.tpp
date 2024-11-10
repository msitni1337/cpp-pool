#include "MutantStack.hpp"

/*constructors*/
template <class T>
MutantStack<T>::iterator::iterator(T &ptr) : _ptr(&ptr)
{
}
template <class T>
MutantStack<T>::iterator::iterator(const MutantStack<T>::iterator &it) : _ptr(it._ptr)
{
}
template <class T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(const MutantStack<T>::iterator &it)
{
    if (this == &it)
        return *this;
    _ptr = it._ptr;
    return *this;
}
template <class T>
MutantStack<T>::iterator::~iterator()
{
}

/*operators*/
template <class T>
void MutantStack<T>::iterator::operator++(int n)
{
    (void)n;
    ++_ptr;
}
template <class T>
void MutantStack<T>::iterator::operator--(int n)
{
    (void)n;
    --_ptr;
}
template <class T>
void MutantStack<T>::iterator::operator++()
{
    _ptr++;
}
template <class T>
void MutantStack<T>::iterator::operator--()
{
    _ptr--;
}
template <class T>
bool MutantStack<T>::iterator::operator!=(const MutantStack<T>::iterator &rhs)
{
    return this->_ptr != rhs._ptr;
}
template <class T>
T MutantStack<T>::iterator::operator*()
{
    return *_ptr;
}
/*constructors*/
template <class T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}
template <class T>
MutantStack<T>::MutantStack(const MutantStack<T> &ms) : std::stack<T>(ms)
{
}
template <class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &ms)
{
    if (this == &ms)
        return *this;
    this = ms;
    return *this;
}
template <class T>
MutantStack<T>::~MutantStack()
{
}
/*member functions*/
template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    MutantStack<T>::iterator start(std::stack<T>::c.front());
    return start;
}
template <class T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    MutantStack<T>::iterator finish(std::stack<T>::c.back());
    finish++;
    return finish;
}