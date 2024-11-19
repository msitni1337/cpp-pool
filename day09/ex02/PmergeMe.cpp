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
            std::string r_num1;
            stream >> r_num1;
            std::cout << "got1: " <<r_num1<<'\n';
            if (is_numeric(r_num1) == false)
                return false;
            long num1 = std::strtol(r_num1.c_str(), NULL, 10);

            std::string r_num2;
            stream >> r_num2;
            std::cout << "got2: " <<r_num2<<'\n';
            if (is_numeric(r_num2) == false)
            {
                if (stream.eof() && r_num2.empty())
                {
                    left_over = num1;
                    is_odd = true;
                    break;
                }
                return false;
            }
            long num2 = std::strtol(r_num2.c_str(), NULL, 10);
            if (num1 < num2)
                std::swap(num1, num2);
            Pair<long> Anum = num1;
            Pair<long> Bnum = num2;
            std::list<Pair<long> >::iterator node = _list[1].insert(BIte, Bnum);
            // Anum.SetOther(*node);
            (void)node;
            _list[0].insert(AIte, Anum);
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
            std::list<Pair<long> >::iterator _AIt = AIt++;
            std::list<Pair<long> >::iterator _AIte = _list[0].end();
            for (; _AIt != _AIte; _AIt++) // iterating over the A list ..
            {
                if (*AIt > *_AIt)
                {
                    std::swap(*AIt, *_AIt);
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
            Pair<long> *other = (*AIt).GetOther();
            if (other == NULL)
                continue;
            std::list<Pair<long> >::iterator _AIt = _list[0].begin();
            std::list<Pair<long> >::iterator _AIte = _list[0].end();
            do
            {
                if (_AIt == _AIte || other->GetValue() <= (*_AIt).GetValue())
                {
                    _list[0].insert(_AIt, *other);
                    break;
                }
                _AIt++;
            } while (_AIt != _AIte);
        }
    }
    if (is_odd)
    {
        std::cout << " set is odd \n";
        std::list<Pair<long> >::iterator AIt = _list[0].begin();
        std::list<Pair<long> >::iterator AIte = _list[0].end();
        do
        {
            if (AIt == AIte || left_over <= (*AIt).GetValue())
            {
                _list[0].insert(AIt, left_over);
                break;
            }
            AIt++;
        } while (AIt != AIte);
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
        std::string r_num1;
        stream >> r_num1;
        if (is_numeric(r_num1) == false)
            return false;
        long num1 = std::strtol(r_num1.c_str(), NULL, 10);
        std::cout << "got1: "<< r_num1<<'\n';
        std::string r_num2;
        stream >> r_num2;
        if (is_numeric(r_num2) == false)
        {
            if (stream.eof() && r_num2.empty())
            {
                left_over = num1;
                is_odd = true;
                break;
            }
            return false;
        }
        std::cout << "got2: "<< r_num2<<'\n';
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
        std::string raw_n;
        long num;
        std::cout << "original set: ";
        while (stream.eof() == false)
        {
            stream >> raw_n;
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
    return;
    {
        if (Sortlist(numbers) == false)
        {
            std::cerr << "Error invalid number\n";
            return;
        }
        std::stringstream stream(numbers);
        std::string raw_n;
        long num;
        std::cout << "original set: ";
        while (stream.eof() == false)
        {
            stream >> raw_n;
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