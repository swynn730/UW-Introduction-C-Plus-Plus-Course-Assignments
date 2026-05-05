#include "TestHarness.h"
#include <iostream>

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);

    return 0;
}
