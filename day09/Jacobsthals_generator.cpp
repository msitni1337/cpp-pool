#include <cmath>
#include <iostream>

int main()
{
    for (size_t i = 0; i < 52; i++)
    {
        long t = std::pow(2, i + 1);
        if (i % 2 == 0)
            t += 1;
        else
            t -= 1;
        t /= 3;
        std::cout << t << ", ";
    }
    std::cout << std::endl;
}