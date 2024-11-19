#include "PmergeMe.hpp"

int main(int c, char **v)
{
    if (c == 2)
    {
        PmergeMe p(v[1]);
        exit(0);
        return 0;
    }
    std::cout << "Bad arguments\nUsage: " << v[0] << " \"[Numbers ..]\"\n";
    return 1;
}