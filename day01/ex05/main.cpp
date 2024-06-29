#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "Executing every level from DEBUG TO ERROR\n\n";
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4 && (harl.complain(levels[i]), true); i++);
    return 0;
}