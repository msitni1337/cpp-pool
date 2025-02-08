#include "PmergeMe.hpp"

static inline bool is_numeric(std::string& param)
{
    size_t i = 0;

    for (; i < param.length() && std::isdigit(param[i]); i++)
        ;
    if (i == param.length())
        return true;
    return false;
}
static std::string get_next_string(std::stringstream& stream)
{
    std::string str;

    do
    {
        str.clear();
        stream >> str;
    } while (str.length() == 0 && stream.eof() == false);
    return str;
}
static inline size_t get_count(std::string numbers)
{
    size_t            count = 0;
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
bool PmergeMe::SortDeque(std::string string)
{
    (void)string;
    return true;
}
bool PmergeMe::SortVector(std::string string)
{
    size_t Jacobsthals[14] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};
    std::vector<std::pair<long, long> > pairs_vector;
    long                                left_over;
    bool                                is_odd = false;
    // spliting the pairs into A and B chains
    {
        std::stringstream stream(string);
        while (stream.eof() == false)
        {
            std::string r_num1 = get_next_string(stream);
            if (r_num1.length() == 0)
                break;
            if (is_numeric(r_num1) == false)
                return false;
            long        num1   = std::strtol(r_num1.c_str(), NULL, 10);
            std::string r_num2 = get_next_string(stream);
            if (r_num2.length() == 0)
            {
                left_over = num1;
                is_odd    = true;
                break;
            }
            if (is_numeric(r_num2) == false)
                return false;
            long num2 = std::strtol(r_num2.c_str(), NULL, 10);
            if (num1 < num2)
                std::swap(num1, num2);
            pairs_vector.insert(pairs_vector.end(), std::pair<long, long>(num1, num2));
        }
    }
    // sorting by the A chain
    if (pairs_vector.size() > 1)
    {
        if (pairs_vector[0].first > pairs_vector[1].first)
            std::swap(pairs_vector[0], pairs_vector[1]);
        for (size_t i = 2; i < pairs_vector.size(); i++)
        {
            std::pair<long, long>                         pair = pairs_vector[i];
            std::vector<std::pair<long, long> >::iterator position =
                GetBinaryInsertPairLocationInVector(
                    pairs_vector.begin(), pairs_vector.begin() + i, pair
                );
            pairs_vector.erase(pairs_vector.begin() + i);
            pairs_vector.insert(position, pair);
        }
    }
    // Inserting sorted A chain to the sorted vector
    if (pairs_vector.size())
    {
        std::vector<std::pair<long, long> >::iterator it = pairs_vector.begin();
        _vector.insert(_vector.end(), it->second);
        for (; it != pairs_vector.end(); it++)
            _vector.insert(_vector.end(), it->first);
    }
    {
        for (size_t i = 1; i < sizeof(Jacobsthals) / sizeof(size_t); i++)
        {
            size_t last_jacobsthal = Jacobsthals[i - 1];
            size_t jacobsthal      = Jacobsthals[i];
            if (last_jacobsthal >= pairs_vector.size())
                break;
            std::vector<std::pair<long, long> >::iterator it;
            if (jacobsthal < pairs_vector.size())
                it = pairs_vector.begin() + jacobsthal;
            else
                it = (pairs_vector.end() - 1);
            for (; it != pairs_vector.begin() + (last_jacobsthal - 1); it--)
                BinaryInsertIntoVector(it->second);
        }
    }
    if (is_odd)
    {
        std::cout << "Binary inserting left over: " << left_over << std::endl;
        BinaryInsertIntoVector(left_over);
    }
    return true;
}
std::vector<std::pair<long, long> >::iterator PmergeMe::GetBinaryInsertPairLocationInVector(
    std::vector<std::pair<long, long> >::iterator begin,
    std::vector<std::pair<long, long> >::iterator end, std::pair<long, long> pair
)
{
    std::cout << "Getting insert location for pair: (" << pair.first << "," << pair.second << ")"
              << std::endl;
    if (pair.first > (end - 1)->first)
        return end;
    if (pair.first < begin->first)
        return begin;
    for (; end - begin > 2;)
    {
        std::vector<std::pair<long, long> >::iterator half = begin + ((end - begin) / 2);
        if (pair.first == half->first)
        {
            end = half;
            break;
        }
        if (pair.first < half->first)
            end = half;
        if (pair.first > half->first)
            begin = half;
    }
    if (pair.first <= end->first)
        return end;
    return begin;
}
void PmergeMe::BinaryInsertIntoVector(long number)
{
    std::cout << "Binary inserting the value: " << number << " into vector:" << std::endl;
    std::vector<long>::iterator it = _vector.begin();
    for (; it != _vector.end(); it++)
        std::cout << *it << ", ";
    std::cout << std::endl;

    if (number > *(_vector.end() - 1))
    {
        _vector.insert(_vector.end(), number);
        return;
    }
    if (number < *_vector.begin())
    {
        _vector.insert(_vector.begin(), number);
        return;
    }
    std::vector<long>::iterator begin = _vector.begin();
    std::vector<long>::iterator end   = _vector.end() - 1;
    for (; end - begin > 2;)
    {
        std::vector<long>::iterator half = begin + ((end - begin) / 2);
        if (number == *half)
        {
            end = half;
            break;
        }
        if (number < *half)
            end = half;
        if (number > *half)
            begin = half;
    }
    if (number <= *end)
        _vector.insert(end, number);
    else
        _vector.insert(begin, number);
}
void PmergeMe::PrintDeque(std::string numbers)
{
    std::stringstream stream(numbers);
    long              num;
    std::cout << "[using std::deque] Before : \n";
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
    std::cout << "[using std::deque] After : \n";
    std::deque<long>::iterator it = _deque.begin();
    for (; it != _deque.end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';
}
void PmergeMe::PrintVector(std::string numbers)
{
    std::stringstream stream(numbers);
    long              num;
    std::cout << "[using std::vector] Before : \n";
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
    std::cout << "[using std::vector] After : \n";
    std::vector<long>::iterator it = _vector.begin();
    for (; it != _vector.end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';
}
bool PmergeMe::AreSorted()
{
    {
        for (size_t i = 0; _deque.size() && i < _deque.size() - 1; i++)
            if (_deque[i] > _deque[i + 1])
                return false;
    }
    {
        for (size_t i = 0; _deque.size() && i < _deque.size() - 1; i++)
            if (_deque[i] > _deque[i + 1])
                return false;
    }
    return true;
}
PmergeMe::PmergeMe(std::string numbers)
{
    timeval then, now;
    long    deque_time;
    long    vector_time;
    size_t  count = get_count(numbers);

    gettimeofday(&then, NULL);
    if (SortDeque(numbers) == false)
    {
        std::cerr << "Error invalid number\n";
        return;
    }
    gettimeofday(&now, NULL);
    deque_time = ((now.tv_sec - then.tv_sec) * 1000000) + now.tv_usec - then.tv_usec;
    gettimeofday(&then, NULL);
    if (SortVector(numbers) == false)
    {
        std::cerr << "Error invalid number\n";
        return;
    }
    gettimeofday(&now, NULL);
    vector_time = ((now.tv_sec - then.tv_sec) * 1000000) + now.tv_usec - then.tv_usec;
    if (AreSorted() == false)
    {
        std::cerr << "Error numbers are not sorted\n";
        return;
    }
    PrintDeque(numbers);
    PrintVector(numbers);
    std::cout << "Time to process a range of " << count << " elements with std::deque container "
              << deque_time << " us\n";
    std::cout << "Time to process a range of " << count << " elements with std::vector container "
              << vector_time << " us\n";
}
PmergeMe::PmergeMe(const PmergeMe& pmm)
{
    *this = pmm;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& pmm)
{
    if (this != &pmm)
    {
        _deque  = pmm._deque;
        _vector = pmm._vector;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}