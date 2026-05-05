#pragma once
#include "ProjectCode_API.h"
#include <vector>
#include <ostream>


class DynamicArray
{
public:
	// If compiling on Windows, be sure to prepend any public member functions
	// with PROJECTCODE_API so they're accessible from the unit test module.
	// See ProjectCode_API.h for more information.


	// On Windows, at least one API must be exported in order for a library to be
	// generated. Without this, UnitTestExe will complain about ProjectCode.lib
	// not existing, which thwarts building this starter code out of the box.

	void put(int index, int value);

	int get(int index) const;

	void remove(int index);

	int size() const;
		
	int operator[](const int index) const;	// Read only.

	int& operator[](const int index);		// Read and write.

private:
	std::vector<int> MyDynamicArray;
	int OutOfBounds = -1;
};

std::ostream& operator<<(std::ostream& os, const DynamicArray& dynamicArray);