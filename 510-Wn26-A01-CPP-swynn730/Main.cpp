#include "TestHarness.h"
#include <iostream>
#include <string>

int main()
{
    int userInt = 0;
    double userDouble = 0.0;
    std::string userString = "";

    std::cout << "Enter an int, a double and a word, seperated by a space, tab or newline." << std::endl;

    std::cin >> userInt >> userDouble >> userString;

    std::cout << "You entered, " << "Int=" << userInt << ", " << "Double=" << userDouble << ", " << "String=" << userString << std::endl;

    TestResult tr;
    TestRegistry::runAllTests(tr);

    return 0;
}