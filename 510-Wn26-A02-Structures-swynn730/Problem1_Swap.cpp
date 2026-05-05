#include "TestHarness.h"
#include "Problem1_Swap.h"
#include <iostream>


void Swap_Ptr(int* valuePtrA, int* valuePtrB)
{
    if(valuePtrA != nullptr || valuePtrB != nullptr)
    {
        int valuePtrC = *valuePtrA;
        *valuePtrA = *valuePtrB;
        *valuePtrB = valuePtrC;
    }
}

void Swap_Ref(int &valueRefA, int &valueRefB)
{
    int valueRefC = valueRefA;
    valueRefA = valueRefB;
    valueRefB = valueRefC;
}

TEST(intPtrValueNotSwapped, Swap_Ptr)
{
    int valueA = 7;
    int valueB = 3;
    
    CHECK_EQUAL(7, valueA)
    CHECK_EQUAL(3, valueB)

    Swap_Ptr(&valueA, &valueB);

    CHECK_EQUAL(3, valueA)
    CHECK_EQUAL(7, valueB)
}

TEST(intRefValueSwapped, Swap_Ref)
{
    int valueA = 7;
    int valueB = 3;
    
    CHECK_EQUAL(7, valueA)
    CHECK_EQUAL(3, valueB)
    
    Swap_Ref(valueA, valueB);
    
    CHECK_EQUAL(3, valueA)
    CHECK_EQUAL(7, valueB)
}