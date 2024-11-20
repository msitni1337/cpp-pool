#pragma once
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <vector>
#include <sys/time.h>

typedef struct timeval t_time;

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
    bool _is_pair;
    T _A;
    T _B;

public:
    Pair(const T& A, const T& B) : _is_pair(true), _A(A), _B(B) {};
    Pair(const T& A) : _is_pair(false), _A(A) {};
    Pair(const Pair<T> &pair) : _is_pair(pair._is_pair), _A(pair._A), _B(pair._B) {};
    Pair<T> operator=(const Pair<T> &pair)
    {
        if (&pair == this)
            return *this;
        _is_pair = pair._is_pair, _A = pair._A, _B = pair._B;
        return *this;
    };
    ~Pair() 
    {};
    const bool& isPair() const
    {
        return _is_pair;
    };
    void SetisPair(bool b)
    {
        _is_pair = b;
    };
    const T& GetA() const
    {
        return _A;
    };
    const T& GetB() const
    {
        return _B;
    };

};
template<class T>
int operator<(const Pair<T> &a, const Pair<T> &b)
{
    return (a.GetA() < b.GetA());
};

class PmergeMe
{

private:
    std::multiset<Pair<long> > _mset;
    std::list<Pair<long> > _list;

public:
    PmergeMe(std::string numbers);
    PmergeMe(const PmergeMe &pmm);
    PmergeMe &operator=(const PmergeMe &pmm);
    ~PmergeMe();

private:
    bool PerformMultiSet(std::string numbers);
    bool PerformList(std::string numbers);
    bool Sortlist(std::string string);
    bool SortMultiset(std::string string);
};