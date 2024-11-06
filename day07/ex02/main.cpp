#include "Array.tpp"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>

int main(int c, char **v)
{
    if (c == 1)
    {
        std::cout << "Bad arguments.\nusage: " << v[0] << " [Array of numbers]\n";
        return 1;
    }

    Array<int> array(c - 1);
    std::cout << "Array initialized with size " << array.size() << "\n";
    std::cout << "Array elements initialized to:\n";
    for (int i = 0; i < c - 1; i++)
    {
        std::cout << array[i] << '\n';
        array[i] = std::atoi(v[i + 1]);
    }
    int response = 0;
    while (true)
    {
        std::cout << "Enter index to fetch the number (negative to exit): ";
        std::cin >> response;
        if (response < 0)
            break;
        try
        {
            std::cout << "Value at index [" << response << "] is:\n";
            std::cout << array[response] << '\n';
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception caught.\n";
            std::cerr << "What: " << e.what() << '\n';
        }
    };
    {
        std::cout << "\nCopying array to array2..\n";
        Array<int> array2 = array;
        std::cout << "Listing array2 elements..\n";
        for (size_t i = 0; i < array2.size(); i++)
            std::cout << array2[i] << '\n';
        std::cout << "Deleting Array2..\n";
    }
    std::cout << "Listing original array elements..\n";
    for (size_t i = 0; i < array.size(); i++)
        std::cout << array[i] << '\n';
    return 0;
}
