#include "Harl.hpp"

Harl::Harl()
{
}
Harl::~Harl()
{
}
void Harl::debug(void)
{
    std::cerr << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n\n";
}
void Harl::info(void)
{
    std::cerr << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n\n";
}
void Harl::warning(void)
{
    std::cerr << "[WARNING]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n\n";
}
void Harl::error(void)
{
    std::cerr << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level)
{
    void (Harl::*methods[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int index = 0;
    for (; index < 4 && levels[index].compare(level); index++)
        ;
    switch (index)
    {
    case 0:
        (this->*methods[0])();
        (this->*methods[1])();
        (this->*methods[2])();
        (this->*methods[3])();
        break;
    case 1:
        (this->*methods[1])();
        (this->*methods[2])();
        (this->*methods[3])();
        break;
    case 2:
        (this->*methods[2])();
        (this->*methods[3])();
        break;
    case 3:
        (this->*methods[3])();
        break;
    default:
        std::cerr << "[ Probably complaining about insignificant problems ]\n";
        break;
    }
}
