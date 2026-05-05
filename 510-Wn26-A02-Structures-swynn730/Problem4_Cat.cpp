#include "TestHarness.h"
#include "Problem4_Cat.h"
#include <memory>
#include <iostream>

std::unique_ptr<char[]> cat(const char* valueA, const char* valueB) {
    size_t valueALen = std::strlen(valueA);
    size_t valueBLen = std::strlen(valueB);
    size_t catValueLength = valueALen + valueBLen + 1;  // Space for the required null terminator.
    auto unique_cat_char_array = std::make_unique<char[]>(catValueLength);
    std::copy(valueA, valueA + valueALen, unique_cat_char_array.get());
    std::copy(valueB, valueB + valueBLen, unique_cat_char_array.get() + valueALen);
    unique_cat_char_array[catValueLength - 1] = '\0';   // Required null terminator.
    return unique_cat_char_array;
}

std::string cat(const std::string &valuePtrA, const std::string &valuePtrB) {
    return valuePtrA + valuePtrB;
}

TEST(checkExpectedConcatenationResult, cat)
{
    const char* valueA = "ab";
    const char* valueB = "cde";
    
    auto unique_cat_char_array_ptr = cat(valueA, valueB);

    CHECK_EQUAL("abcde", unique_cat_char_array_ptr.get());
}

TEST(checkExpectedConcatenationResultString, catString)
{
    const std::string valueA = "a";
    const std::string valueB = "b";
    
    std::string cat_string = cat(valueA, valueB);

    CHECK_EQUAL("ab", cat_string);
}

/*
The second option, using std::string, is the better approach because there is less room for error. 
std::string handles memory management automatically while with the C-style string approach, 
the programmer has to handle memory management themselves: allocating on the heap, etc. 
In addition, the programmer has to make sure to include the null terminator or else undefined 
behavior will happen when trying to access the character array. More observationally, overall, 
less code ends up needing to be written to accomplish the same thing as C-style strings. 
Therefore, std::string is the better approach overall because it's easier to understand 
and less error prone making it the superior and recommended option.
*/