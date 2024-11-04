#include "easyfind.tpp"
#include <iostream>
#include <vector>

int main(int c, char **v)
{
    if (c == 1)
    {
        std::cout << "Bad arguments.\nusage: " << v[0] << " [Array of numbers]\n";
        return 1;
    }
    std::vector<int> vec(c - 1);
    for (int i = 0; i < c - 1; i++)
        vec[i] = atoi(v[i + 1]);

    while (true)
    {
        int choice;
        std::cout << "search for (negative to exit): ";
        std::cin >> choice;
        if (choice < 0)
            break;
        std::vector<int>::iterator found = ::easyfind<std::vector<int>, std::vector<int>::iterator>(vec, choice);
        if (found != vec.end())
            std::cout << "element found: " << *found << '\n';
        else
            std::cout << "element not found.\n";
    }
    return 0;
}
