#include "Functions.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {
    srand(static_cast<unsigned int>(time(0)));
    int random = rand() % 3;
    
    switch(random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
    // We'll use a dummy variable and check if the cast was successful
    Base* dummy = &p;
    
    if (dynamic_cast<A*>(dummy))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(dummy))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(dummy))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}