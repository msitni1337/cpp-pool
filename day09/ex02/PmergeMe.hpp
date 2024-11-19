#pragma once
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>
#include <list>

template<class T> void swap(T &a, T &b)
{
    T tmp = a;

    a = b;
    b = tmp;
}

template <class T>
class Pair
{
private:
    T _value;
    Pair<T> *_other;

public:
    Pair(const T value) : _value(value), _other(NULL) {};
    Pair(const Pair<T> &pair) : _value(pair._value), _other(pair._other) {};
    Pair<T> operator=(const Pair<T> &pair)
    {
        _value = pair._value;
        _other = pair._other;
        return *this;
    };
    ~Pair() {};
    Pair<T> *GetOther() const
    {
        return _other;
    };
    void SetOther(Pair<T> *other)
    {
        _other = other;
    };
    const T &
    GetValue() const
    {
        return _value;
    };
};

class PmergeMe
{

private:
    std::multiset<long> _mset[2];
    std::list<Pair<long> > _list[2];

public:
    PmergeMe(std::string numbers);
    PmergeMe(const PmergeMe &pmm);
    PmergeMe &operator=(const PmergeMe &pmm);
    ~PmergeMe();

private:
    bool Sortlist(std::string string);
    bool SortMultiset(std::string string);
};