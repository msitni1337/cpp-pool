#include "Brain.hpp"

Brain::Brain()
{
    for (unsigned int i = 0; i < sizeof(ideas) / sizeof(std::string); i++)
        ideas[i] = "random idea..";
    std::cout << "Ctor for Brain class called\n";
}
Brain::Brain(const Brain &brain)
{
    for (unsigned int i = 0; i < sizeof(ideas) / sizeof(std::string); i++)
        ideas[i] = brain.ideas[i];
}
Brain &Brain::operator=(const Brain &brain)
{
    if (this != &brain)
    {
        for (unsigned int i = 0; i < sizeof(ideas) / sizeof(std::string); i++)
            ideas[i] = brain.ideas[i];
    }
    return *this;
}
Brain::~Brain()
{
    std::cout << "Dtor for Brain class called\n";
}
