#include "Span.hpp"
#include <iostream>

int main()
{
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        try
        {
            sp.addNumber(11);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        int nums[] = {1, 2, 3};
        try
        {
            sp.addNumbers(nums, nums + 3);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        Span sp = Span(3);
        int nums[] = {1, 2, 3};
        std::cout << "Adding range of numbers at once:\n";
        sp.addNumbers(nums, nums + 3);
        for (size_t i = 0; i < sp.getCurr(); i++)
        {
            std::cout << sp[i] << '\n';
        }
    }
    {
        Span sp = Span(3);
        std::cout << "Calculating shortest & longest span without adding numbers:\n";
        try
        {
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}