// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: crend const", "[DynamicArray][crend]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		THEN("crend is equal to crbegin") {
			REQUIRE(arr.crend() == arr.crbegin());
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		THEN("crend is not equal to crbegin") {
			REQUIRE(arr.crend() != arr.crbegin());
		}
	}
}