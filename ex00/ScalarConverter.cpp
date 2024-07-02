#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal) {
    std::istringstream iss(literal);
    int n;
    iss >> n;
    return iss.eof() && !iss.fail();
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") return true;
    if (literal[literal.length() - 1] != 'f') return false;
    std::istringstream iss(literal.substr(0, literal.length() - 1));
    float f;
    iss >> f;
    return iss.eof() && !iss.fail();
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf") return true;
    std::istringstream iss(literal);
    double d;
    iss >> d;
    return iss.eof() && !iss.fail();
}

void ScalarConverter::convertChar(const std::string& literal) {
    char c = literal[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertInt(const std::string& literal) {
    int i = std::atoi(literal.c_str());
    std::cout << "char: ";
    if (i < 0 || i > 127) std::cout << "impossible" << std::endl;
    else if (i < 32 || i > 126) std::cout << "Non displayable" << std::endl;
    else std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertFloat(const std::string& literal) {
    float f;
    if (literal == "nanf") f = std::numeric_limits<float>::quiet_NaN();
    else if (literal == "+inff") f = std::numeric_limits<float>::infinity();
    else if (literal == "-inff") f = -std::numeric_limits<float>::infinity();
    else f = std::atof(literal.c_str());

    std::cout << "char: ";
    if (f != f || f < 0 || f > 127) std::cout << "impossible" << std::endl;
    else if (f < 32 || f > 126) std::cout << "Non displayable" << std::endl;
    else std::cout << "'" << static_cast<char>(f) << "'" << std::endl;

    std::cout << "int: ";
    if (f != f || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;

    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertDouble(const std::string& literal) {
    double d;
    if (literal == "nan") d = std::numeric_limits<double>::quiet_NaN();
    else if (literal == "+inf") d = std::numeric_limits<double>::infinity();
    else if (literal == "-inf") d = -std::numeric_limits<double>::infinity();
    else d = std::atof(literal.c_str());

    std::cout << "char: ";
    if (d != d || d < 0 || d > 127) std::cout << "impossible" << std::endl;
    else if (d < 32 || d > 126) std::cout << "Non displayable" << std::endl;
    else std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    std::cout << "int: ";
    if (d != d || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    if (isChar(literal)) convertChar(literal);
    else if (isInt(literal)) convertInt(literal);
    else if (isFloat(literal)) convertFloat(literal);
    else if (isDouble(literal)) convertDouble(literal);
    else std::cout << "Error: Invalid input" << std::endl;
}