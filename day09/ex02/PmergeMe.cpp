#include "PmergeMe.hpp"

static inline bool is_numeric(std::string &param)
{
    size_t i = 0;
    if (param[i] == '-' || param[i] == '+')
        i++;
    if (i >= param.length())
        return false;
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
        std::list<Pair<long> >::iterator AIte = _list[0].end();
        std::list<Pair<long> >::iterator BIte = _list[1].end();
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
            std::list<Pair<long> >::iterator Bnum = _list[1].insert(BIte, num2);
            std::list<Pair<long> >::iterator Anum = _list[0].insert(AIte, num1);
            (*Anum).SetOther(&(*Bnum));
        }
    }
    // sorting A
    {
        std::list<Pair<long> >::iterator AIt = _list[0].begin();
        std::list<Pair<long> >::iterator AIte = _list[0].end();

        bool swapped = true;
        for (; swapped && AIt != AIte; AIt++) // iterating over the A list ..
        {
            bool swapped = false;
            std::list<Pair<long> >::iterator _AIt = AIt;
            _AIt++;
            for (; _AIt != AIte; _AIt++) // iterating over the A list ..
            {
                if ((*AIt).GetValue() > (*_AIt).GetValue())
                {
                    ::swap((*AIt), (*_AIt));
                    swapped = true;
                }
                else
                    break;
            }
            if (swapped)
                AIt = _list[0].begin();
        }
    }
    {
        std::list<Pair<long> >::iterator AIt = _list[0].begin();
        std::list<Pair<long> >::iterator AIte = _list[0].end();
        for (; AIt != AIte; AIt++) // iterating over the A list ..
        {
            Pair<long> *other = (Pair<long> *)(*AIt).GetOther();
            if (other == NULL)
                continue;
            (*AIt).SetOther(NULL);
            std::list<Pair<long> >::iterator _AIt = _list[0].begin();
            std::list<Pair<long> >::iterator _AIte = _list[0].end();
            while (_AIt != _AIte)
            {
                if (other->GetValue() <= (*_AIt).GetValue())
                {
                    _list[0].insert(_AIt, *other);
                    break;
                }
                _AIt++;
                if (AIt == AIte)
                    _list[0].insert(_AIt, *other);
            }
        }
    }
    if (is_odd)
    {
        std::list<Pair<long> >::iterator AIt = _list[0].begin();
        std::list<Pair<long> >::iterator AIte = _list[0].end();
        while (AIt != AIte)
        {
            if (left_over <= (*AIt).GetValue())
            {
                _list[0].insert(AIt, left_over);
                break;
            }
            AIt++;
            if (AIt == AIte)
                _list[0].insert(AIt, left_over);
        }
    }
    return true;
}

bool PmergeMe::SortMultiset(std::string string)
{
    long left_over;
    bool is_odd = false;

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
    {
        if (SortMultiset(numbers) == false)
        {
            std::cerr << "Error invalid number\n";
            return;
        }
        std::stringstream stream(numbers);
        long num;
        std::cout << "original set: ";
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
        std::cout << "sorted set: ";
        std::multiset<long>::iterator it = _mset[0].begin();
        std::multiset<long>::iterator ite = _mset[0].end();
        for (; it != ite; it++)
            std::cout << *it << ' ';
        std::cout << '\n';
    }
    {
        if (Sortlist(numbers) == false)
        {
            std::cerr << "Error invalid number\n";
            return;
        }
        std::stringstream stream(numbers);
        long num;
        std::cout << "original set: ";
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
        std::cout << "sorted set: ";
        std::list<Pair<long> >::iterator it = _list[0].begin();
        std::list<Pair<long> >::iterator ite = _list[0].end();
        for (; it != ite; it++)
            std::cout << (*it).GetValue() << ' ';
        std::cout << '\n';
    }
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