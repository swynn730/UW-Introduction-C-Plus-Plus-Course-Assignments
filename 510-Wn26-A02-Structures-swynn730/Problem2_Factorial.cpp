#include "TestHarness.h"
#include "Problem2_Factorial.h"


constexpr int Calculate_Factorial(int value) {
    if(value == 0) {
        return 1;
    }

    int factorial = 1;
    for(int i = value; i > 0; i--) {
        factorial *= value;
        value -= 1;
    }
    return factorial;
}

TEST(intCorrectFactorialCalculatedAtRunTime, Calculate_Factorial)
{   
    CHECK_EQUAL(1, Calculate_Factorial(0));
    CHECK_EQUAL(6, Calculate_Factorial(3));
}

TEST(intCorrectFactorialCalculatedAtCompileTime, Calculate_Factorial)
{   
    constexpr int factorialResultA = Calculate_Factorial(0);
    constexpr int factorialResultB = Calculate_Factorial(3);
    CHECK_EQUAL(1, factorialResultA);
    CHECK_EQUAL(6, factorialResultB);
}