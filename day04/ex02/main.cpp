#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // -> this should not be compilable...
    //  AAnimal animal;

    std::cout << "simple heap allocation test:\n";
    {
        AAnimal *array[100];

        size_t i = 0;
        for (; i < 50; i++)
            array[i] = new Dog();
        for (; i < 100; i++)
            array[i] = new Cat();

        for (i = 0; i < 100; i++)
            delete array[i];
    }

    return 0;
}

/*
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
*/
