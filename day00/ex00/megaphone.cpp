#include <iostream>

void put_cap(const char*arg)
{
    size_t i;

    i = 0;
    while (arg && arg[i])
    {
        if (arg[i] >= 'a' && arg[i] <= 'z')
            std::cout << (char)(arg[i] - 32);
        else
            std::cout << arg[i];
        i++;
    }
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