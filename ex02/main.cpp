#include "Functions.hpp"
#include <iostream>

int main() {
    for (int i = 0; i < 10; ++i) {
        Base* ptr = generate();
        std::cout << "Generated object " << i + 1 << ":" << std::endl;
        std::cout << "Identified by pointer: ";
        identify(ptr);
        std::cout << "Identified by reference: ";
        identify(*ptr);
        std::cout << std::endl;
        delete ptr;
    }
    return 0;
}