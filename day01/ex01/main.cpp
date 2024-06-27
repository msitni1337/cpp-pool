#include "Zombie.hpp"
#include "stdlib.h"

int main(int c, const char **v)
{
    if (c != 3)
    {
        std::cout << "Bad arguments\n";
        std::cout << v[0] << " [num of zombies] [name of zombies]\n";
        return 1;
    }
    int zombieCount = atoi(v[1]);
    if (zombieCount < 1)
    {
        std::cout << "num of zombies must be a positive value > 0.\n";
        return 1;
    }
    std::string name = v[2];
    if (name.length() == 0)
    {
        std::cout << "name of zombies must not be an empty string.\n";
        return 1;
    }
    Zombie *hord = zombieHorde(zombieCount, name);
    for (int i = 0; i < zombieCount; i++)
        hord[i].announce();
    delete [] hord;    
    return 0;
}