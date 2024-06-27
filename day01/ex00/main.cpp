#include "Zombie.hpp"

int main(int c, const char **v)
{
    for (int i = 1; i < c; i++)
        randomChump(v[i]);
    
    for (int i = 1; i < c; i++)
    {
        Zombie* zombie = newZombie(v[i]);
        zombie->announce();
        delete zombie;
    }
    return 0;
}