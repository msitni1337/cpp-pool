#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <fstream>

Base *generate(void)
{
    Base *b;
    std::ifstream randfile("/dev/rand");
    unsigned int c;
    randfile >> c;
    c %= 3;
    if (c == 0)
        b = new A();
    else if (c == 1)
        b = new B();
    else
        b = new C();
    randfile.close();
    return b;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "object pointer is of concrete type: A.\n";
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "object pointer is of concrete type: B.\n";
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "object pointer is of concrete type: C.\n";
}

void identify(Base &p)
{
    try 
    {
        (void) dynamic_cast<A &>(p);
        std::cout << "object reference is of concrete type: A.\n";
        return;
    }
    catch (std::exception &e)
    {}
    try 
    {
        (void) dynamic_cast<B &>(p);
        std::cout << "object reference is of concrete type: B.\n";
        return;
    }
    catch (std::exception &e)
    {}
    try 
    {
        (void) dynamic_cast<C &>(p);
        std::cout << "object reference is of concrete type: C.\n";
        return;
    }
    catch (std::exception &e)
    {}
}

int main()
{
    while (1)
    {
        Base* base = generate();
        identify(base);
        identify(*base);
        delete base;
        std::cout << "Press Enter to run again...\n";
        std::cin.get();
    }
}