#include "TestHarness.h"

#include "Probe.h"
#include "Target.h"


TEST(reportCreationCount, Target)
{
    Target::resetCounts();

    Target t1 =  Target{};
    Target t2 =  Target{};
    Target t3 =  Target{};

    CHECK_EQUAL(3, t1.reportCreationCount());
}

TEST(reportCurrentCount, Target)
{
    Target::resetCounts();

    Target* t1 =  new Target{};
    Target* t2 =  new Target{};
    Target* t3 =  new Target{};

    delete t3;
    delete t2;

    CHECK_EQUAL(1, (*t1).reportCurrentCount());

    delete t1;
}

TEST(ostreamOperatorOverload, Target)
{
    Target::resetCounts();
    
    Target* t1 =  new Target{};
    Target* t2 =  new Target{};
    Target* t3 =  new Target{};

    delete t3;
    delete t2;
    std::stringstream stream;
    stream << (*t1);

    CHECK_EQUAL("The creation count is: 3, The current count is: 1", stream.str());
    delete t1;
}