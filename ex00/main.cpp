#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

void runTest(const std::string& test) {
    std::cout << "\nTesting input: \"" << test << "\"" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    ScalarConverter::convert(test);
    std::cout << "-----------------------------" << std::endl;
}

int main() {
    // Character tests
    runTest("c");
    runTest("z");
    runTest("A");
    runTest("0");
    runTest("~");
    
    // Integer tests
    runTest("0");
    runTest("42");
    runTest("-42");
    runTest("2147483647");  // INT_MAX
    runTest("-2147483648"); // INT_MIN
    
    // Float tests
    runTest("0.0f");
    runTest("4.2f");
    runTest("-4.2f");
    runTest("42.0f");
    runTest("3.40282e+38f"); // Close to FLT_MAX
    runTest("-3.40282e+38f"); // Close to -FLT_MAX
    
    // Double tests
    runTest("0.0");
    runTest("4.2");
    runTest("-4.2");
    runTest("1.79769e+308"); // Close to DBL_MAX
    runTest("-1.79769e+308"); // Close to -DBL_MAX
    
    // Special values
    runTest("nan");
    runTest("nanf");
    runTest("+inf");
    runTest("-inf");
    runTest("+inff");
    runTest("-inff");
    
    // Edge cases
    runTest("2147483648"); // Just over INT_MAX
    runTest("-2147483649"); // Just under INT_MIN
    
    // Invalid inputs
    runTest("hello");
    runTest("42a");
    runTest("a42");
    runTest("4.2.2");
    runTest("4,2");

    return 0;
}