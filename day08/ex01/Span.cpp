#include "Span.hpp"

const char *Span::SpanIsFullException::what() const throw()
{
    return "Span::SpanIsFullException";
}
const char *Span::IndexOutOfBoundException::what() const throw()
{
    return "Span::IndexOutOfBoundException";
}
const char *Span::ImpossibleToFindASpan::what() const throw()
{
    return "Span::ImpossibleToFindASpan";
}
Span::Span(unsigned int N) : _capacity(N), _curr(0)
{
    _buff = new int[N];
}
Span::Span(const Span &sp) : _buff(NULL)
{
    *this = sp;
}
Span &Span::operator=(const Span &sp)
{
    if (this == &sp)
        return *this;
    delete[] _buff;
    _capacity = sp._capacity;
    _buff = new int[_capacity];
    std::copy(sp._buff, sp._buff + sp._curr, _buff);
    return *this;
}
int &Span::operator[](unsigned int index)
{
    if (index < _curr)
        return _buff[index];
    throw Span::IndexOutOfBoundException();
}
Span::~Span()
{
    delete[] _buff;
}
void Span::addNumber(int num)
{
    if (_curr >= _capacity)
        throw Span::SpanIsFullException();
    _buff[_curr] = num;
    _curr++;
}
void Span::addNumbers(int *first, int *last)
{
    if (last == first)
        return;
    if (last - first > _capacity - _curr)
        throw Span::SpanIsFullException();
    std::copy(first, last, _buff + _curr);
    _curr += last - first;
}
unsigned int Span::shortestSpan() const
{
    if (_curr < 2)
        throw Span::ImpossibleToFindASpan();
    Span tmpsp = *this;
    std::sort(tmpsp._buff, tmpsp._buff + _curr);
    unsigned int sh_span = __UINT32_MAX__;
    for (size_t i = 0; i < _curr - 1; i++)
    {
        unsigned int tmp = tmpsp._buff[i + 1] - tmpsp._buff[i];
        if (tmp < sh_span)
            sh_span = tmp;
    }
    return sh_span;
}
unsigned int Span::longestSpan() const
{
    if (_curr < 2)
        throw Span::ImpossibleToFindASpan();
    int *max = std::max_element(_buff, _buff + _curr);
    int *min = std::min_element(_buff, _buff + _curr);
    return (*max - *min);
}
unsigned int Span::getCapacity() const
{
    return _capacity;
}
unsigned int Span::getCurr() const
{
    return _curr;
}