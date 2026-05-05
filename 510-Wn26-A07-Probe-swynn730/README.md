C++ Classes—Data and Member Functions—Part 2
Provide tests using CppUnitLite. Place each class declaration into its own .h file. Place each class definition into its own .cpp file.

This assignment addresses two programming problems (the Probe and the Array).

Assignment
Starting with this assignment, source code is now structured in a multi-module hierarchy that builds CppUnitLite into a static library, your assignment code into a dynamic library, and your unit test code into an executable file that links to the other two projects. This brings us closer to how real-world software projects are structured, and is a useful introduction to the concepts needed for assignment 9.

If compiling on Windows, make sure to decorate any externally-accessible functions with PROJECTCODE_API so they're visible from the unit test module. We'll dig into the reasons why later in the course.

Probe
Define a probe (class Probe) that can be inserted into a class (class Target) as a test coverage device. (Note: the data and function members of the probe cannot be static. The probe itself must be declared static in the probed class.)  The probe keeps track of the number of instances of the target that currently exist, and how many have been created since the program was started. The probe is to respond with appropriate tracking information when the class instance containing the probe is queried. It will be necessary to figure out the best way to present the query. Demonstrate your probe on a class with multiple instances. 
Use operator overloading in the Probe class to increment and decrement its member data.
Overload the ostream operator to support printing of information of the class Probe.
Overload the ostream operator to support printing of information of the class Target.  Hint: the information that a Target should stream is the information that its contained Probe can stream.
Use the delete keyword to delete the copy constructor, copy assignment operator, move constructor, and move assignment operator for the probe.
Array
An array is a common structure for storing information. In many languages, one must specify the size of the array in advance of its use. Frequently, however, one does not know how much data will need to be stored. A common solution is to declare the array to be much larger than is expected to be necessary hoping it will be large enough. This is certainly not the most efficient solution.

Design an array that expands as data is entered and contracts when it is removed. You will need to define a private data structure to support the array. Use one of the STL collection classes such as vector, list, or deque. Support the following access methods:
// Overwrites an existing element, or adds a new element as necessary.
// If an element exists at index, the existing element is overwritten.
// If an element does not exist at the index, a new element is added. If necessary, the array
// must expand to accommodate the new element. 
void put(int index, int value);

// returns the element at index.
int get(int index) const;

// removes the element at the specified index. The array may contract.
void remove(int index);
Provide two overloads of operator[]:

Provide a const member function overload which returns the data at the specified array index. Be sure to handle out-of-bounds access and provide a default behavior when the data doesn’t exist.
Provide a non-const member function overload which allows the data to be overwritten at the specified array index.
Write an overloaded ostream operator to display the contents of the array.
Describe why the compiler generated constructor and assignment operators are sufficient for DynamicArray.
