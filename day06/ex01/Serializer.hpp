#pragma once
#include "Data.hpp"

class Serializer
{
private:
    Serializer();
    ~Serializer();
public:
    static uintptr_t    Serialize(Data*ptr);
    static Data*        Deserialize(uintptr_t raw);
};