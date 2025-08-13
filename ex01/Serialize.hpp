#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP
#include <stdio.h>
#include <iostream>
#include "Data.hpp"
#include <stdint.h>

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
        //uintptr_t es un entro sin signo lo suficientemente grande como para almacenar cualquier dirección de memoria (o puntero). uint -> unsigned integer, ptr -> pointer, _t -> type
};

#endif
