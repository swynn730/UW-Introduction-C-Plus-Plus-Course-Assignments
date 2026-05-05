#pragma once

#include "ProjectCode_API.h"

#include "Probe.h"


class Target
{
	// If compiling on Windows, be sure to prepend any public member functions
	// with PROJECTCODE_API so they're accessible from the unit test module.
	// See ProjectCode_API.h for more information.
public:
	explicit Target();
    Target(const Target& src) = default;				// copy constructor
    Target(Target&& src) = default;						// move constructor
    Target& operator=(const Target& src) = default;		// copy assignment operator
    Target& operator=(Target&& src) = default;			// move assignment operator
    ~Target();

	int reportCreationCount() const;
	int reportCurrentCount() const;

	static void resetCounts();
	
	friend std::ostream& operator<<(std::ostream& os, const Target& t);

private:
	static inline Probe p;
};