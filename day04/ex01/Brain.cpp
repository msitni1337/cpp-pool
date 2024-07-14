#include "Brain.hpp"

Brain::Brain(const std::string &idea)
{
    for (unsigned int i = 0; i < sizeof(ideas) / sizeof(std::string); i++)
        ideas[i] = "Brain is thinking of " + idea;
    std::cout << "Ctor for Brain class called\n";
}
Brain::Brain(const Brain &brain)
{
    for (unsigned int i = 0; i < sizeof(ideas) / sizeof(std::string); i++)
        ideas[i] = brain.ideas[i];
    std::cout << "Copy Ctor for Brain class called\n";
}
Brain &Brain::operator=(const Brain &brain)
{
    if (this != &brain)
    {
        for (unsigned int i = 0; i < sizeof(ideas) / sizeof(std::string); i++)
            ideas[i] = brain.ideas[i];
    }
    std::cout << "Copy Assignement for Brain class called\n";
    return *this;
}
Brain::~Brain()
{
    std::cout << "Dtor for Brain class called\n";
}
