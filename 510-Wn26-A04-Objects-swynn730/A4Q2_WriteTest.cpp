#include "TestHarness.h"
#include "A4Q2_Write.h"
#include <iostream>


// ================================================================
TEST(checkStreamStringIntResult, write)
{   std::stringstream stream;
    write(stream, 3);
    CHECK_EQUAL("3", stream.str());
}

TEST(checkStreamStringFloatResult, write)
{
    std::stringstream stream;
    write(stream, 7.0f);
    CHECK_EQUAL("7.0", stream.str());
}

TEST(checkStreamStringStringResult, write)
{
    std::stringstream stream;
    write(stream, "Samus_Aran");
    CHECK_EQUAL("Samus_Aran", stream.str());
}
// ================================================================