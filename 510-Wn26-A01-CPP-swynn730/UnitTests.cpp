#include "TestHarness.h"
#include <iostream>
#include <iomanip>
#include <memory>
#include <array>


TEST(intStringIsExpectedStringStreamOutput, stringStream)
{
    int value = 7;
    std::stringstream stream;
    stream << value;
    CHECK_EQUAL("7", stream.str())
}

TEST(doubleStringIsExpectedStringStreamOutput, stringStream)
{
    double value = 7.0;
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << value;
    CHECK_EQUAL("7.0", stream.str())
}

TEST(floatStringIsExpectedStringStreamOutput, stringStream)
{
    float value = 7.000000f;
    std::stringstream stream;
    stream << std::fixed << std::setprecision(6) << value;
    CHECK_EQUAL("7.000000", stream.str())
}

TEST(stringIsExpectedStringStreamOuput, stringStream)
{
    std::string value = "Hello World!";
    std::stringstream stream;
    stream << value;
    CHECK_EQUAL("Hello World!", stream.str())
}

TEST(intStringStreamIsExpectedIntOuput, stringStream)
{
    int value = 0;
    std::stringstream stream("7");
    stream >> value;
    CHECK_EQUAL(7, value)
}

TEST(doubleStringStreamIsExpectedDoubleOuput, stringStream)
{
    double value = 0.0;
    std::stringstream stream("7.0");
    stream >> value;
    CHECK_DOUBLES_EQUAL(7.0, value, 1e-1)
}

TEST(floatStringStreamIsExpectedFloatOuput, stringStream)
{
    float value = 0.0f;
    std::stringstream stream("7.000000");
    stream >> value;
    CHECK_DOUBLES_EQUAL(7.000000, value, 1e-6)
}

TEST(stringStreamIsExpectedStringOuput, stringStream)
{
    std::string value = "";
    std::stringstream stream("Hello World!");
    // This ensures that the whole string is retrieved.
    std::getline(stream, value);
    CHECK_EQUAL("Hello World!", value)
}

TEST(stringStreamIsNotExpectedOuput, stringStream)
{
    int value = 0;
    std::stringstream stream("Hello");
    stream >> value;
    CHECK_EQUAL(true, stream.fail())
}

TEST(intCStyleArrayHasCorrectValues, cStyleArray)
{
    const int ARRAY_SIZE = 10;
    auto cStyleArray = std::make_unique<int[]>(ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int cStyleArrayValue = (i + 1);
        cStyleArray[i] = cStyleArrayValue;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        int cStyleArrayValue = (i + 1);
        CHECK_EQUAL(cStyleArrayValue, cStyleArray[i])
    }
}

TEST(intVectorHasCorrectValues, vector)
{
    const int VECTOR_SIZE = 10;
    std::vector<int> myVector;
    for (int i = 0; i < VECTOR_SIZE; i++) {
        myVector.push_back(i);
    }

    for (int i = 0; i < VECTOR_SIZE; i++) {
        CHECK_EQUAL(i, myVector[i])
    }
}

TEST(floatArrayHasCorrectValues, array)
{
    const int ARRAY_SIZE = 10;
    std::array<float, ARRAY_SIZE> myArray;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        float array_value = (static_cast<float>(i) + 1.1f);
        myArray[i] = array_value;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        float array_value = (static_cast<float>(i) + 1.1f);
        CHECK_DOUBLES_EQUAL(array_value, myArray[i], 1e-1)
    }
}