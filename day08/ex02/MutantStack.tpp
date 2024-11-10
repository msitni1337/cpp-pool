#include "MutantStack.hpp"

/*constructors*/
template <class T>
MutantStack<T>::iterator::iterator(const ms_iterator &it)
{
    (void)it;
}
template <class T>
MutantStack<T>::iterator::iterator(const MutantStack<T>::iterator &it)
{
    (void)it;
}
template <class T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(const MutantStack<T>::iterator &it)
{
    (void)it;
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
}
template <class T>
void MutantStack<T>::iterator::operator--(int n)
{
    (void)n;
}
template <class T>
void MutantStack<T>::iterator::operator++()
{
}
template <class T>
void MutantStack<T>::iterator::operator--()
{
}
template <class T>
bool MutantStack<T>::iterator::operator!=(const MutantStack<T>::iterator &rhs)
{
    (void)rhs;
    return false;
}
template <class T>
T MutantStack<T>::iterator::operator*()
{
    return *this;
}
/*constructors*/
template <class T>
MutantStack<T>::MutantStack()
{
}
template <class T>
MutantStack<T>::MutantStack(const MutantStack<T> &ms)
{
    (void)ms;
}
template <class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &ms)
{
    (void)ms;
}
template <class T>
MutantStack<T>::~MutantStack()
{
}
/*member functions*/
template <class T>
typename MutantStack<T>::iterator &MutantStack<T>::begin()
{
    return *this;
}
template <class T>
typename MutantStack<T>::iterator &MutantStack<T>::end()
{
    return *this;
}