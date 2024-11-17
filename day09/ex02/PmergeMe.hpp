#pragma once
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <list>

class PmergeMe
{
private:
    std::multiset<long> _mset[2];
    std::list<long> _list[2];

public:
    PmergeMe(std::string numbers);
    PmergeMe(const PmergeMe &pmm);
    PmergeMe &operator=(const PmergeMe &pmm);
    ~PmergeMe();

private:
    bool SortMultiset(std::stringstream& numbers);
};
