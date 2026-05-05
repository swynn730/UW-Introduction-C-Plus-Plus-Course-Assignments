#pragma once

#include "ProjectCode_API.h"
#include <ostream>


class Probe
{
	// If compiling on Windows, be sure to prepend any public member functions
	// with PROJECTCODE_API so they're accessible from the unit test module.
	// See ProjectCode_API.h for more information.
public:
    Probe() = default;								// default constructor
    Probe(const Probe& src) = delete;				// copy constructor
    Probe(Probe&& src) = delete;					// move constructor
    Probe& operator=(const Probe& src) = delete;	// copy assignment operator
    Probe& operator=(Probe&& src) = delete;			// move assignment operator
    ~Probe() = default;

	int reportCreationCount() const;
	int reportCurrentCount() const;

	Probe& operator++();							// prefix increment total/current
	Probe& operator--();							// prefix decrement current
	
	void resetCounts();

	friend std::ostream& operator<<(std::ostream& os, const Probe& p);

private:
	int creationCount = 0;
	int currentCount = 0;
};