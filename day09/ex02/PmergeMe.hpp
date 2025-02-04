#pragma once
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <vector>

class PmergeMe
{

private:
    std::multiset<std::pair<long, long> > _pair_multiset;
    std::vector<std::pair<long, long> >   _pair_vector;

public:
    PmergeMe(std::string numbers);
    PmergeMe(const PmergeMe& pmm);
    PmergeMe& operator=(const PmergeMe& pmm);
    ~PmergeMe();

private:
    bool PerformMultiSet(std::string numbers);
    bool PerformList(std::string numbers);
    bool Sortlist(std::string string);
    bool SortMultiset(std::string string);
    bool AreSorted();
    void PrintVector(std::string numbers);
    void PrintMultiset(std::string numbers);
};