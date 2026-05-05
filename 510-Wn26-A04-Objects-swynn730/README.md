C++ Object Concepts
Write CppUnitLite tests to verify correct behavior for all items except #4.

Use auto for variable declarations in your implementation.

Using std::chrono utilities, write three functions: one to add one day, one to add one month, and one to add one year to a Date struct.

struct Date
{
    int year;
    int month;
    int day;
};
Be careful to consider corner cases such as incrementing the last day of the month and leap years.
Pass Dates by reference when appropriate (i.e., Date& or const Date&). For example, the following function returns by value a new Date instance with one day added to the passed-in date.

Date addOneDay(const Date& date);
Populate the C++ header file named A4Q2_write.h with function prototypes for three functions named write. Write the implementations for each write function in the file named A4Q2_write.cpp.   Each write function takes two arguments. The first argument is always std::ostream& os. The second arguments are an int, a float, and a std::string respectively. Each write function should stream its second argument to the passed-in std::ostream. Write cppunitlite unit tests that pass a std::stringstream as the first argument to each function and verify its operation. Write non unit test code that calls each write function and passes std::cout as the first argument (the cout tests are written outside the unit test framework because verification can't easily be automated). Here's the prototype for the first write overload:
void write(std::ostream& os, int value);

Notice that both std::stringstream and std::cout may be passed as the first argument. Both inherit from std::ostream and thus may be used where ever a std::ostream& is used. This is our first use of inheritance in C++. We'll do much more with inheritance as the course progresses.

Write a lambda function that makes the following test pass:
TEST(lambdaTestProblem, lambdas)
{
    auto values = { 2, 4, 6, 8, 10, 12 };
    auto sum = 0;

    std::for_each(values.begin(), values.end(), /*define lambda function here*/);

    CHECK_EQUAL(42, sum);
}
[Note: This section does not require CppUnitLite tests]
Define a simple class with a default constructor, copy constructor, move constructor, and destructor. Annotate each one so that it writes to cout each time it is invoked.
Use =default to compiler-generate the remaining special member functions, thus ensuring compliance with the rule-of-five.
Declare four functions with the following prototypes:
void f1(SimpleClass aSimpleClass);
void f2(SimpleClass aSimpleClass);
void f3(SimpleClass& aSimpleClass);
void f4(SimpleClass* aSimpleClass);
Declare an instance of SimpleClass in the function main and call f1 with that instance as an argument.
Declare an instance of SimpleClass in the function f1. Pass that instance by value, to function, f2.
Declare an instance of the SimpleClass in f2 that uses the copy constructor. Pass that instance by reference to function f3.
Declare a function f4 that takes a pointer to an instance of SimpleClass. Call f4 from within f3 using a pointer to the argument passed into f3.
How many instances of your class were constructed? How many instances of your class were destructed? Why? Write your answer as a code comment.
