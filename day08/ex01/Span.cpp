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
Span::Span(unsigned int N) : _count(N), _curr(0)
{
    _buff = new int[N];
}
Span::Span(const Span &sp)
{
    *this = sp;
}
Span &Span::operator=(const Span &sp)
{
    if (this == &sp)
        return *this;
    delete[] _buff;
    _count = sp._count;
    _buff = new int[_count];
    std::for_each(sp._buff, sp._buff + sp._curr, [this] (int num) -> void {
        (*this)[this->_curr] = num;
        this->_curr++;
    });
    return *this;
}
int &Span::operator[](unsigned int index)
{
    if (index < _count)
        return _buff[index];
    throw Span::IndexOutOfBoundException();
}
Span::~Span()
{
    delete[] _buff;
}
void Span::AddNumber(int num)
{
    if (_curr >= _count)
        throw Span::SpanIsFullException();
    _buff[_curr] = num;
    _curr++;
}
void Span::AddNumbers(int *first, int *last)
{
    if (last - first >= _count - _curr)
        throw Span::SpanIsFullException();
    auto ff = std::for_each(first, last, [this] (int num) {
        (*this)[this->_curr] = num;
        this->_curr++;
    });
}
unsigned int Span::shortestSpan() const
{
}
unsigned int Span::longestSpan() const
{
    if (_curr < 2)
        throw Span::ImpossibleToFindASpan();
    int *max = std::max_element(_buff, _buff + _curr);
    int *min = std::min_element(_buff, _buff + _curr);
    return (max - min);
}
