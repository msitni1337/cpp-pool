#pragma once
#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
    class iterator
    {
    private:
        typedef typename std::deque<T>::iterator ms_iterator;
        ms_iterator _it;
    public:
        iterator(const ms_iterator &it);
        iterator(const MutantStack<T>::iterator &it);
        MutantStack<T>::iterator & operator=(const MutantStack<T>::iterator &it);
        ~iterator();
        void operator++(int n);
        void operator--(int n);
        void operator++();
        void operator--();
        bool operator!=(const MutantStack<T>::iterator &rhs);
        T operator*();
    };

public:
    MutantStack();
    MutantStack(const MutantStack<T> &ms);
    MutantStack<T> &operator=(const MutantStack<T> &ms);
    ~MutantStack();
    MutantStack<T>::iterator &begin();
    MutantStack<T>::iterator &end();
};