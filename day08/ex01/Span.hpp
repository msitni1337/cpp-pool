#pragma once
#include <exception>
#include <algorithm>
#include <cstddef>

class Span
{
public:
    class SpanIsFullException : public std::exception
    {
    private:
    public:
        const char *what() const throw();
    };
    class IndexOutOfBoundException : public std::exception
    {
    private:
    public:
        const char *what() const throw();
    };
    class ImpossibleToFindASpan : public std::exception
    {
    private:
    public:
        const char *what() const throw();
    };

private:
    int *_buff;
    unsigned int _capacity;
    unsigned int _curr;

public:
    Span(unsigned int N);
    Span(const Span &sp);
    Span &operator=(const Span &sp);
    int &operator[](unsigned int index);
    ~Span();
    void addNumber(int num);
    void addNumbers(int *first, int *last);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    unsigned int getCapacity() const;
    unsigned int getCurr() const;
};