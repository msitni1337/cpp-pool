#include "PmergeMe.hpp"

static inline bool is_numeric(std::string &param)
{
    size_t i = 0;
    if (param.length() == 0)
        return true;
    for (; i < param.length() && (param[i] == '-' || param[i] == '+'); i++)
        ;
    if (i >= param.length())
        return false;
    for (; i < param.length() && std::isdigit(param[i]); i++)
        ;
    if (i > 0 && i == param.length())
        return true;
    return false;
}
bool PmergeMe::SortMultiset(std::stringstream &numbers)
{
    long left_over;
    bool is_odd = false;
    while (numbers.eof() == false)
    {
        std::string r_num1;
        numbers >> r_num1;
        if (is_numeric(r_num1) == false)
            return false;
        long num1 = std::strtol(r_num1.c_str(), NULL, 10);
        if (numbers.eof())
        {
            left_over = num1;
            is_odd = true;
            break;
        }
        std::string r_num2;
        numbers >> r_num2;
        if (is_numeric(r_num2) == false)
            return false;
        long num2 = std::strtol(r_num2.c_str(), NULL, 10);
        if (num1 < num2)
            std::swap(num1, num2);
        _mset[0].insert(num1);
        _mset[1].insert(num2);
    }
    std::multiset<long>::iterator it = _mset[1].begin();
    std::multiset<long>::iterator ite = _mset[1].end();
    for (; it != ite; it++)
        _mset[0].insert(*it);
    if (is_odd)
        _mset[0].insert(left_over);
    return true;
}
PmergeMe::PmergeMe(std::string numbers)
{
    std::stringstream stream(numbers);
    if (SortMultiset(stream) == false)
    {
        std::cerr << "Error invalid number\n";
        return;
    }
    stream.seekg(0);

    std::multiset<long>::iterator it = _mset[0].begin();
    std::multiset<long>::iterator ite = _mset[0].end();
    for (; it != ite; it++)
        std::cout << *it << ' ';
    std::cout << '\n';
}
PmergeMe::PmergeMe(const PmergeMe &pmm)
{
    *this = pmm;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &pmm)
{
    if (this != &pmm)
    {
        _mset[0] = pmm._mset[0];
        _mset[1] = pmm._mset[1];
        _list[0] = pmm._list[0];
        _list[1] = pmm._list[1];
    }
    return *this;
}
PmergeMe::~PmergeMe()
{
}