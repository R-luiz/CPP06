#include <iostream>
#include "Serializer.hpp"

int main() {
    Data originalData = {42, 'A', 3.14f};
    Data* originalPtr = &originalData;

    std::cout << "Original pointer: " << originalPtr << std::endl;
    std::cout << "Original data: " << originalPtr->id << ", " 
              << originalPtr->character << ", " << originalPtr->value << std::endl;

    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "Serialized value: " << serialized << std::endl;

    Data* deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;
    std::cout << "Deserialized data: " << deserializedPtr->id << ", " 
              << deserializedPtr->character << ", " << deserializedPtr->value << std::endl;

    if (originalPtr == deserializedPtr) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
}