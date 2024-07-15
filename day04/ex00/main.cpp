#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

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
    std::cout << "\n========== Polymorphisme test: ======================\n";
    {
        const Animal *animals[3] = {new Animal(), new Cat(), new Dog()};
        for (size_t i = 0; i < 3; i++)
            std::cout << animals[i]->getType() << ": ", animals[i]->makeSound();
        for (size_t i = 0; i < 3; i++)
                delete animals[i];
    }
    std::cout << "\n========== Wrong Implementation test: ======================\n";
    {
        const WrongAnimal *animals[2] = {new WrongAnimal(), new WrongCat()};
        for (size_t i = 0; i < 2; i++)
            std::cout << animals[i]->getType() << ": ", animals[i]->makeSound();
        for (size_t i = 0; i < 2ete animals[i];; i++)
                delete animals[i];
    }
    return 0;
}