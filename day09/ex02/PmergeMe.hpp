#pragma once
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <vector>

class PmergeMe
{

private:
    std::deque<long>  _deque;
    std::vector<long> _vector;

public:
    PmergeMe(std::string numbers);
    PmergeMe(const PmergeMe& pmm);
    PmergeMe& operator=(const PmergeMe& pmm);
    ~PmergeMe();

private:
    std::vector<std::pair<long, long> >::iterator GetBinaryInsertPairLocationInVector(
        std::vector<std::pair<long, long> >::iterator begin,
        std::vector<std::pair<long, long> >::iterator end, std::pair<long, long> pair
    );
    std::vector<long>::iterator GetBinaryInsertLocationInVector(long number);
    bool                        SortDeque(std::string string);
    bool                        SortVector(std::string string);
    bool                        AreSorted();
    void                        PrintDeque(std::string numbers);
    void                        PrintVector(std::string numbers);
};