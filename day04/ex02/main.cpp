#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // -> this line of code bellow should not be compilable...
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
