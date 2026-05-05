C++ I/O, Types, Declarations, and CppUnitLite
1.  Write a program that prompts the user to enter an int, a double, and a word on the command line. Read the values into variables of the appropriate data type with std::cin. Write the 3 values to std::cout. You may implement this as a standalone program, or within the main() of the provided program, but do not implement it as a unit test!

2.  Write CppUnitLite tests which verify std::stringstream. Write separate tests to:

write an int/double/float/string into a stream, and verify the stream has the expected string output with CHECK_EQUAL.
read an int/double/float/string from a pre-initialized stream, and verify the data has the expected values with CHECK_EQUAL or CHECK_DOUBLES_EQUAL.
initialize a stringstream with the string "Hello". Attempt to stream this value into an int variable. Write a check that verifies this fails.
Be sure to use CHECK_DOUBLES_EQUAL for floating-point types (`float` and `double`), and CHECK_EQUAL for other types.
Remember that tests should only evaluate one thing at a time, so don't combine these into monolithic tests. You should have a total of 9 individual tests when done.
3.  Write a CppUnitLite test that uses the array form of unique_ptr to allocate an (built-in, C-style) array of 10 integers. Use CHECK_EQUAL to verify the array has the correct values.

4.  Write a CppUnitLite test that creates a std::vector of int. Add 10 integers to the vector with the values 0-9. Use CHECK_EQUAL to verify the vector has the correct values.

5.  Write a CppUnitLite test that creates a std::array of float. Add 10 floats to the array. Use CHECK_DOUBLES_EQUAL to verify the array has the correct values.
