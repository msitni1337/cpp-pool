#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;

    data.age       = 10;
    data.distance  = 100.0f;
    data.grade     = 'A';
    data.price     = 100.0;
    uintptr_t raw  = Serializer::Serialize(&data);
    Data    * des = Serializer::Deserialize(raw);
    std::cout << "des->age = " << des->age << "\ndes->distance = " << des->distance
        << "\ndes->grade = " << des->grade << "\ndes->price = " << des->price << '\n';
}