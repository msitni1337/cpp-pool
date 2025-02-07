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
#include <cmath>

class PmergeMe
{

private:
    std::list<long> _list;
    std::vector<long>   _vector;

public:
    PmergeMe(std::string numbers);
    PmergeMe(const PmergeMe& pmm);
    PmergeMe& operator=(const PmergeMe& pmm);
    ~PmergeMe();

private:
    bool PerformMultiSet(std::string numbers);
    bool PerformList(std::string numbers);
    bool SortList(std::string string);
    bool SortMultiset(std::string string);
    bool AreSorted();
    void PrintVector(std::string numbers);
    void PrintMultiset(std::string numbers);
};