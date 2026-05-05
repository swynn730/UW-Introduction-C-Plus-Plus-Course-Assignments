Pointers, Arrays, Structures, Expressions, and Statements
In this assignment, use separate .cpp files for each numbered item.
Example: Problem1_Swap.cpp will contain functions you wrote to satisfy item 1, and the corresponding unit test cases which verify their behavior.

Swap: Write a function that swaps (exchanges the values of two integers). Use int* as the argument types. Write a second swap function using a reference (i.e., int&) as the argument types. (Note: The C++ library has a std::swap. In most situations just use the library version. But, for this homework, write your own swap).  Write unit tests to verify correct behavior.
Factorial: Write a function that returns the factorial of its single int argument. Declare the function constexpr. Write an example where the factorial result is determined at compile-time, and another where the factorial result is determined at run time, and use comments to clarify which is which. Write unit tests that verify both the compile-time and run-time usage.
MonthTable: Define a table of the names of months of the year and the number of days in each month. Write out that table to a std::stringstream. Do this two ways, in unit tests:
Once using a std::array of std::string for the names, and another std::array for the number of days.
A second time using a std::array of structs, with each structure holding the name of a month (as a std::string) and the number of days in it.
Cat (as in "concatenate"):
Write the function cat() that takes two C-style strings (i.e., const char*) arguments and returns a std::unique_ptr<char[]> that contains the concatenation of the arguments. Use std::make_unique to use heap memory for the result. Write CppUnitLite tests to verify correct behavior.
Write a second function cat() that takes two const std::string& arguments and returns a std::string that is a concatenation of the arguments. The std::string version does not require new. Write CppUnitLite tests to verify correct behavior.
Which is the better approach? Add a code comment with your rationale for which is the better approach.
ParseInt: Implement the function: std::optional<int> ParseInt(const std::string& s); Verify your function implementation passes these two unit tests (below). Write an additional unit test that verifies use of std::optional::value_or().
TEST(ParseIntSuccess, Parse)
{
    auto result = ParseInt("99");

    CHECK(result.has_value());
    CHECK_EQUAL(99, *result);
}

TEST(ParseIntFailure, Parse)
{
    auto result = ParseInt("Hello");

    CHECK(!result.has_value());
}

Submitting Your Assignment
Accept Assignment 2Links to an external site. and create an "Assignment2" branch.

Do include your code .cpp and .h files and your unit test .cpp files
Do not include exe, obj, or other results of compilation and linking. These would bloat the repository, and should not be under version control.
You may optionally turn in Visual Studio .vcproj and .sln files, or Makefiles (your-environment dependent)
It's best to place all the files in a single directory as it make it easier to find the pertinent files
Use the same names for class and function names as specified in the assignments. This improves grading quality as it makes it easier to find things.
As the agreement between the UW and GitHub is insufficient for GitHub to be an official record for student work, you must upload a zip file with your GitHub repository to Canvas.

Using Git, add, commit, and push your changes to your GitHub repo
Create a pull request from your "Assignment2" branch to the "main" branch in your GithHub repo
Create a zip file of your GitHub repo
In Canvas, click the Start Assignment button to turn in your assignment, upload the zip file of your repo and enter the URL for your pull request in the Comments field.
