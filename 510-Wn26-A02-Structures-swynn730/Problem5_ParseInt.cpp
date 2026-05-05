#include "TestHarness.h"
#include <optional>
#include "Problem5_ParseInt.h"


std::optional<int> ParseInt(const std::string& s)
{
	try 
	{	
		return std::stoi(s);	
	} 
	catch (const std::exception& e) 
	{	return std::nullopt;
	}
}

TEST(ParseIntSuccess, Parse)
{
	const auto result = ParseInt("99");

	CHECK(result.has_value());
	CHECK_EQUAL(99, *result);
}

TEST(ParseIntFailure, Parse)
{
	const auto result = ParseInt("Hello");

	CHECK(!result.has_value());
}

TEST(ParseIntValueOr, Parse)
{
	const auto result = ParseInt("Hello");

	CHECK_EQUAL(-1, result.value_or(-1));
}