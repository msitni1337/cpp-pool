#include "PmergeMe.hpp"

static inline bool is_numeric(std::string &param)
{
    size_t i = 0;

    for (; i < param.length() && std::isdigit(param[i]); i++)
        ;
    if (i == param.length())
        return true;
    return false;
}
static std::string get_next_string(std::stringstream & stream)
{
    std::string str;
    
    do
    {
        str.clear();
        stream >> str;
    }
    while(str.length() == 0 && stream.eof() == false);
    return str;
}
bool PmergeMe::Sortlist(std::string string)
{
    long left_over;
    bool is_odd = false;
    {
        std::stringstream stream(string);
        while (stream.eof() == false)
        {
            std::string r_num1 = get_next_string(stream);
            if (r_num1.length() == 0)
                break;
            if (is_numeric(r_num1) == false)
                return false;
            long num1 = std::strtol(r_num1.c_str(), NULL, 10);
            std::string r_num2 = get_next_string(stream);
            if (r_num2.length() == 0)
            {
                left_over = num1;
                is_odd = true;
                break;
            }
            if (is_numeric(r_num2) == false)
                return false;
            long num2 = std::strtol(r_num2.c_str(), NULL, 10);
            if (num1 < num2)
                std::swap(num1, num2);
            Pair<long> pair(num1, num2);
            _list.insert(_list.end(), pair);
        }
    }
    // sorting A
    {
        std::list<Pair<long> >::iterator AIt = _list.begin();
        std::list<Pair<long> >::iterator AIte = _list.end();

        bool swapped = true;
        for (; swapped && AIt != AIte; AIt++) // iterating over the A list ..
        {
            bool swapped = false;
            std::list<Pair<long> >::iterator _AIt = AIt;
            _AIt++;
            for (; _AIt != AIte; _AIt++) // iterating over the A list ..
            {
                if (AIt->GetA() > _AIt->GetA())
                {
                    ::swap((*AIt), (*_AIt));
                    swapped = true;
                }
                else
                    break;
            }
            if (swapped)
                AIt = _list.begin();
        }
    }
    {
        std::list<Pair<long> >::iterator AIt = _list.begin();
        std::list<Pair<long> >::iterator AIte = _list.end();
        for (; AIt != AIte; AIt++) // iterating over the A list ..
        {
            if ((*AIt).isPair() == false)
                continue;
            std::list<Pair<long> >::iterator _AIt = _list.begin();
            std::list<Pair<long> >::iterator _AIte = _list.end();
            while (_AIt != _AIte)
            {
                if (AIt->GetB() <= _AIt->GetA())
                {
                    _list.insert(_AIt, AIt->GetB());
                    break;
                }
                _AIt++;
                if (AIt == AIte)
                    _list.insert(_AIt, AIt->GetB());
            }
        }
    }
    {
        if (is_odd)
        {
            std::list<Pair<long> >::iterator AIt = _list.begin();
            std::list<Pair<long> >::iterator AIte = _list.end();
            while (AIt != AIte)
            {
                if (left_over <= AIt->GetA())
                {
                    _list.insert(AIt, left_over);
                    break;
                }
                AIt++;
                if (AIt == AIte)
                    _list.insert(AIt, left_over);
            }
    }
    }
    return true;
}

bool PmergeMe::SortMultiset(std::string string)
{
    long left_over;
    bool is_odd = false;
    {
        std::stringstream stream(string);
        while (stream.eof() == false)
        {
            std::string r_num1 = get_next_string(stream);
            if (r_num1.length() == 0)
                break;
            if (is_numeric(r_num1) == false)
                return false;
            long num1 = std::strtol(r_num1.c_str(), NULL, 10);
            std::string r_num2 = get_next_string(stream);
            if (r_num2.length() == 0)
            {
                left_over = num1;
                is_odd = true;
                break;
            }
            if (is_numeric(r_num2) == false)
                return false;
            long num2 = std::strtol(r_num2.c_str(), NULL, 10);
            if (num1 < num2)
                std::swap(num1, num2);
            Pair<long> pair(num1, num2);
            _mset.insert(pair);
        }
    }
    std::multiset<Pair<long> >::iterator it = _mset.begin();
    std::multiset<Pair<long> >::iterator ite = _mset.end();
    for (; it != ite; it++)
    {
        if (it->isPair() == false)
            continue;
        Pair<long> A(it->GetB());
        _mset.insert(A);
    }
    if (is_odd)
        _mset.insert(left_over);
    return true;
}
bool PmergeMe::PerformMultiSet(std::string numbers)
{
    if (SortMultiset(numbers) == false)
    {
        std::cerr << "Error invalid number\n";
        return false;
    }
    std::stringstream stream(numbers);
    long num;
    std::cout << "original set: \n";
    while (stream.eof() == false)
    {
        std::string raw_n;
        stream >> raw_n;
        if (raw_n.length() == 0)
            break;
        num = std::strtol(raw_n.c_str(), NULL, 10);
        std::cout << num << ' ';
    }
    std::cout << '\n';
    std::cout << "sorted set: \n";
    std::multiset<Pair<long> >::iterator it = _mset.begin();
    std::multiset<Pair<long> >::iterator ite = _mset.end();
    for (; it != ite; it++)
        std::cout << it->GetA() << ' ';
    std::cout << '\n';
    return true;
}
bool PmergeMe::PerformList(std::string numbers)
{
    if (Sortlist(numbers) == false)
    {
        std::cerr << "Error invalid number\n";
        return false;
    }
    std::stringstream stream(numbers);
    long num;
    std::cout << "original set: \n";
    while (stream.eof() == false)
    {
        std::string raw_n;
        stream >> raw_n;
        if (raw_n.length() == 0)
            break;
        num = std::strtol(raw_n.c_str(), NULL, 10);
        std::cout << num << ' ';
    }
    std::cout << '\n';
    std::cout << "sorted set: \n";
    std::list<Pair<long> >::iterator it = _list.begin();
    std::list<Pair<long> >::iterator ite = _list.end();
    for (; it != ite; it++)
        std::cout << it->GetA() << ' ';
    std::cout << '\n';
    return true;
}
inline size_t get_count(std::string numbers)
{
    size_t count = 0;
    std::stringstream stream(numbers);

    while (stream.eof() == false)
    {
        std::string r_num1 = get_next_string(stream);
        if (r_num1.length() == 0)
            break;
        count++;
    }
    return count;
}
PmergeMe::PmergeMe(std::string numbers) : _list()
{
    t_time then, now;
    float multiset_time;
    float list_time;
    size_t count = get_count(numbers);

    gettimeofday(&then, NULL);
    if (PerformMultiSet(numbers) == false)
        return;
    gettimeofday(&now, NULL);
    multiset_time   = ((now.tv_sec - then.tv_sec) * 1000 * 100) + now.tv_usec - then.tv_usec;
    gettimeofday(&then, NULL);
    if (PerformList(numbers) == false)
        return;
    gettimeofday(&now, NULL);
    list_time       = ((now.tv_sec - then.tv_sec) * 1000 * 100) + now.tv_usec - then.tv_usec;
    std::cout << "Time to process a range of " << count << " elements with std::multiset " << multiset_time << " us\n";
    std::cout << "Time to process a range of " << count << " elements with std::list " << list_time << " us\n";
}
PmergeMe::PmergeMe(const PmergeMe &pmm)
{
    *this = pmm;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &pmm)
{
    if (this != &pmm)
    {
        _mset = pmm._mset;
        _list = pmm._list;
    }
    return *this;
}
PmergeMe::~PmergeMe()
{
}