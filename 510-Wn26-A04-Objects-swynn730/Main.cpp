#include "TestHarness.h"
#include <iostream>
#include "A4Q2_Write.h"
#include "A4Q4_SimpleClass.cpp"


int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);
    
    write(std::cout, 3);
    std::cout << std::endl;

    write(std::cout, 7.0f);
    std::cout << std::endl;

    write(std::cout, "Samus_Aran");
    std::cout << std::endl;

    SimpleClass sc = SimpleClass();
    sc.f1(sc);

    return 0;
}