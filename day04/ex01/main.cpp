#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    {
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete j;
        delete i;
    }
    std::cout << "================================================" << std::endl;
    {
        const Animal *animals[3] = {new Animal(), new Cat(), new Dog()};
        for (size_t i = 0; i < 3; i++)
            std::cout << animals[i]->getType() << ": ", animals[i]->makeSound(),
                delete animals[i];
    }
    return 0;
}