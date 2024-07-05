#include <iostream>

void put_cap(const char*arg)
{
    size_t i;

    i = 0;
    while (arg && arg[i])
        std::cout << (char) std::toupper(arg[i]), i++;
}

int main(int c, const char**v)
{
    if (c == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        for (int i = 1; i < c; i++)
            put_cap(v[i]);
    }
    std::cout << std::endl;
    return 0;   
}