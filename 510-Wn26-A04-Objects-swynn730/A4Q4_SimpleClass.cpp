#include <iostream>


class SimpleClass
{
    public:
        // Constructor.
        SimpleClass()
        {
            std::cout << "Constructor invoked." << std::endl;
        }

        // Copy Constructor.
        SimpleClass(const SimpleClass& otherSimpleClass) 
        {
            std::cout << "Copy constructor invoked." << std::endl;
        }

        // Move Constructor.
        SimpleClass(SimpleClass&& otherSimpleClass)
        {
            std::cout << "Move constructor invoked." << std::endl;
        }
        
        // Copy Assignment.
        SimpleClass& operator=(const SimpleClass& otherSimpleClass) = default;

        // Move Assignment.
        SimpleClass& operator=(SimpleClass&& otherSimpleClass) = default;

        // Destructor.
        ~SimpleClass()
        {
            std::cout << "Destructor invoked." << std::endl;
        }

        // Pass by value.
        void f1(SimpleClass aSimpleClass) 
        {
            SimpleClass sc = SimpleClass();
            sc.f2(sc);
            std::cout << "f1 invoked." << std::endl;
        }

        // Pass by value.
        void f2(SimpleClass aSimpleClass) 
        {
            SimpleClass sc = SimpleClass(aSimpleClass);
            sc.f3(sc);
            std::cout << "f2 invoked." << std::endl;
        }

        // Pass by reference.
        void f3(SimpleClass& aSimpleClass) 
        {
            aSimpleClass.f4(&aSimpleClass);
            std::cout << "f3 invoked." << std::endl;
        }

        // Pass by pointer.
        void f4(SimpleClass* aSimpleClass)
        {
            std::cout << "f4 invoked." << std::endl;
        }
};

/*
5 instances were constructed (2 using default constructor and 3 using copy constructor).
5 instances were destructed.

Explanation:
I create an instance in main. Total instances = 1. Instance A.
I call f1 in main, pass it an instance and invoke copy constructor. Total instances = 2. Instance B.
I create an instance in f1. Total instances = 3. Instance C.
I call f2 in f1, pass it an instance and invoke copy constructor. Total instances = 4. Instance D.
I create an instance in f2 using copy constructor. Total instances = 5. Instance E.
I call f3 in f2 but am passing the instance I created in f2 by reference, so no new instances are made.
I call f4 in f3 but am passing the instance I created in f2 that I passed by reference in f3 to f4 as a pointer, so no new instances are made.
f1-f4 are invoked in descending order because of how they are nested method calls. 
Likewise, the instances are destructed in the opposite order they are constructed.
Therefore, constructed = A, B, C, D, E, destructed = E, D, C, B, A.
*/