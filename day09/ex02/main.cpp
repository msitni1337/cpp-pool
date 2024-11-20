#include "PmergeMe.hpp"

int main(int c, char **v)
{
    // ./PmergeMe 2 5 6 3 "3 4 4 5 3 6" not sorted ??
    if (c > 1)
    {
        std::string args;
        for (int i = 1; i < c; i++)
        {
            args += v[i];        
            args += " ";        
        }
        PmergeMe p(args);
        exit(0);
    }
    std::cout << "Bad arguments\nUsage: " << v[0] << " \"[Numbers ..]\"\n";
    return 1;
}