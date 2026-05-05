C++ Classes and Structures
Write CppUnitLite tests to verify class functionality.

Define a class CharQueue with the following public interface:

class CharQueue
{
public:
    CharQueue();                     // default constructor
    explicit CharQueue(size_t size);
    CharQueue(const CharQueue& src); // copy constructor
    CharQueue(CharQueue&& src);      // move constructor
    CharQueue& operator=(const CharQueue& src); // copy assignment operator
    CharQueue& operator=(CharQueue&& src);      // move assignment operator

    void enqueue(char ch);
    char dequeue();

    bool isEmpty() const;

    size_t capacity() const;
};
Copy the public interface above into two different versions of CharQueue:

1.  CharQueue1:

Use a std::unique_ptr<char[]> array as the private data member. Use std::make_unique to grow the array used for the queue as needed. Add other private member variables as needed to track size and position.
Overload the copy constructor and copy assignment operator to implement a deep copy.
Overload the move constructor and move assignment operator to implement move semantics for the class.
Note: The compiler-generated version would work fine for this use case. For the purposes of this assignment, implement them manually.
2.  CharQueue2: use a std::deque<char> as the private data member. Use compiler-generated versions of the copy constructor, copy assignment operator, move constructor, and move assignment operator. A bitwise copy of std::deque is sufficient to copy its contents, so custom copy logic is unnecessary.

Place each class in two separate files named for the class. For example, for CharQueue1 place the class declaration in A5Q1_CharQueue1.h and the class definition in A5Q1_CharQueue1cpp.

Create unit tests for CharQueue1. E.g., A5Q2_CharQueue1Tests.cpp. The identical tests will work for CharQueue2. Once you have a good set of unit tests for CharQueue1, copy them to A5Q2_CharQueue2Tests.cpp, and change the class names to test CharQueue2.

For all remaining assignments in the course we will follow this general convention. That is, place the class declaration into a .h file named for the class, and place the class definition in a .cpp file named for the class.
