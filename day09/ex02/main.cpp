#include "PmergeMe.hpp"

int main(int c, char **v)
{
    //"1 2 3 4 5 6                  4       5 5 5 -55 88 1000000 " double free?
    if (c == 2)
    {
        PmergeMe p(v[1]);
        return 0;
    }
    std::cout << "Bad arguments\nUsage: " << v[0] << " \"[Numbers ..]\"\n";
    return 1;
}