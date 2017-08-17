// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: cend const", "[DynamicArray][end][cend]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		THEN("cend is equal to cbegin") {
			REQUIRE(arr.cend() == arr.cbegin());
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		THEN("cend is not equal to cbegin") {
			REQUIRE(arr.cend() != arr.cbegin());
		}
	}
}