#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
    Serializer(); // Private constructor to prevent instantiation
    Serializer(const Serializer&); // Private copy constructor
    Serializer& operator=(const Serializer&); // Private assignment operator
    ~Serializer(); // Private destructor

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif