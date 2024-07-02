
#include "ScalarConverter.hpp"


void ScalarConverter::convert(const std::string& literal) {
    char* endptr;
    double value;

    // Check if it's a character literal
    if (literal.length() == 1 && !isdigit(literal[0])) {
        value = static_cast<double>(literal[0]);
    }
    // Try to convert to double
    else {
        value = strtod(literal.c_str(), &endptr);
        
        // Check if conversion was successful
        if (*endptr != '\0' && strcmp(endptr, "f") != 0) {
            // Special cases for inf and nan
            if (literal == "nan" || literal == "nanf") {
                value = std::numeric_limits<double>::quiet_NaN();
            }
            else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
                value = std::numeric_limits<double>::infinity();
            }
            else if (literal == "-inf" || literal == "-inff") {
                value = -std::numeric_limits<double>::infinity();
            }
            else {
                std::cout << "Error: Invalid input" << std::endl;
                return;
            }
        }
    }

    // Convert to char
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127) {
        std::cout << "impossible";
    } else if (isprint(static_cast<char>(value))) {
        std::cout << "'" << static_cast<char>(value) << "'";
    } else {
        std::cout << "Non displayable";
    }
    std::cout << std::endl;

    // Convert to int
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
        std::cout << "impossible";
    } else {
        std::cout << static_cast<int>(value);
    }
    std::cout << std::endl;

    // Convert to float
    std::cout << "float: ";
    if (std::isnan(value)) {
        std::cout << "nanf";
    } else if (std::isinf(value)) {
        std::cout << (value > 0 ? "+inff" : "-inff");
    } else {
        std::cout << static_cast<float>(value) << "f";
    }
    std::cout << std::endl;

    // Convert to double
    std::cout << "double: ";
    if (std::isnan(value)) {
        std::cout << "nan";
    } else if (std::isinf(value)) {
        std::cout << (value > 0 ? "+inf" : "-inf");
    } else {
        std::cout << value;
    }
    std::cout << std::endl;
}