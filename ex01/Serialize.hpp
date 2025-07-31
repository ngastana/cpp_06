#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP
#include <stdio.h>
#include <iostream>
#include "Data.hpp"

class Serialize
{
    private:
        Serialize();
        Serialize(const Serialize &copy);
        Serialize& operator=(const Serialize &other);
        ~Serialize();
        
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
