#pragma once
#include <cstddef>
#include <exception>

template <class T>
class Array
{
public:
    class IndexOutOfBoundException : public std::exception
    {
    private:
    public:
        const char *what() const throw();
    };

private:
    T *_buff;
    unsigned int _count;

public:
    Array();
    Array(unsigned int count);
    Array(const Array<T> &arr);
    Array<T> &operator=(const Array<T> &arr);
    ~Array();
    size_t size() const;
    T &operator[](unsigned int index);
};