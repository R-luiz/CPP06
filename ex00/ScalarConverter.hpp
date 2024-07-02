
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>

class ScalarConverter {
private:
    ScalarConverter();
public:
    static void convert(const std::string& literal);
};

#endif
