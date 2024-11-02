#include "iter.tpp"
#include <iostream>
#include <cstring>
#include <string>

static void ft_print_char(char &c)
{
    std::cout << c;
}

static void ft_print_char_arrows(char &c)
{
    if (c == '\n')
        std::cout << c;
    else
        std::cout << "->>" << c << "<<-";
}

static void ft_print_char_bracket(char &c)
{
    if (c == '\n')
        std::cout << c;
    else
        std::cout << '[' << c << ']';
}

int main(int c, char **v)
{
    if (c == 2)
    {
        size_t arg_len = std::strlen(v[1]);
        std::cout << "original:\n";
        iter(v[1], arg_len, ft_print_char);
        std::cout << '\n';
        std::cout << "ft_print_char_arrows:\n";
        iter(v[1], arg_len, ft_print_char_arrows);
        std::cout << '\n';
        std::cout << "ft_print_char_bracket:\n";
        iter(v[1], arg_len, ft_print_char_bracket);
        std::cout << '\n';
        return 0;
    }
    std::cout << "Bad arguments.\nusage: " << v[0] << " [string to convert]\n";
    return 1;
}
