#include "TestHarness.h"

#include "DynamicArray.h"


TEST(expansion, DynamicArray)
{
    DynamicArray x;
    x.put(0, 0);
    x.put(1, 1);
    x.put(2, 2);
    x.put(10, 3);

    CHECK_EQUAL(11, x.size());
    CHECK_EQUAL(3, x.get(x.size() - 1));
    CHECK_EQUAL(-1, x.get(x.size() - 2));
}

TEST(contraction, DynamicArray)
{
    DynamicArray x;
    x.put(0, 0);
    x.put(1, 1);
    x.put(2, 2);
    x.put(3, 3);

    x.remove(2);

    CHECK_EQUAL(3, x.size());
    CHECK_EQUAL(3, x.get(2));
}

TEST(access, DynamicArray)
{
    DynamicArray x;
    x.put(0, 7);
    CHECK_EQUAL(7, x.get(0));
}

TEST(accessOutOfBounds, DynamicArray)
{
    DynamicArray x;
    CHECK_EQUAL(-1, x.get(20));
}

TEST(accessConstOverload, DynamicArray)
{
    // Can only read.
    DynamicArray x;
    x.put(0, 0);
    x.put(1, 1);
    const DynamicArray& xConst = x;
    CHECK_EQUAL(1, xConst[1]);
}

TEST(accessNonConstOverload, DynamicArray)
{
    // Can read and write.
    DynamicArray x;
    x.put(0, 0);
    x.put(1, 1);
    x[1] = 2;
    CHECK_EQUAL(2, x[1]);
}

TEST(accessConstOverloadOutOfBounds, DynamicArray)
{
    // Can only read.
    DynamicArray x;
    x.put(0, 0);
    x.put(1, 1);
    const DynamicArray& xConst = x;
    CHECK_EQUAL(-1, xConst[20]);
}

TEST(accessNonConstOverloadOutOfBounds, DynamicArray)
{
    // Can read and write.
    DynamicArray x;
    x.put(0, 0);
    x.put(1, 1);
    x[1] = 2;
    CHECK_EQUAL(-1, x[20]);
}

TEST(displayContents, DynamicArray)
{
    // Can read and write.
    DynamicArray x;
    x.put(0, 0);
    x.put(1, 1);
    x.put(2, 2);
    x.put(3, 3);
    x.put(4, 4);
    x.put(5, 5);
    x.put(6, 6);

    std::stringstream stream;
    stream << x;
    CHECK_EQUAL("[0, 1, 2, 3, 4, 5, 6]", stream.str());
}

/*
The compiler generated constructor and assignment operators are sufficient for DynamicArray
because DynamicArray only contains simple member data types such as std::vector and int. 
These types already correctly manage their own memory and copy behavior because they are simple. 
As a result, the default copying performed by the compiler is enough; no custom deep copy logic is required.
*/