// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: end", "[DynamicArray][end]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		THEN("end is equal to begin") {
			REQUIRE(arr.end() == arr.begin());
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		THEN("end is not equal to begin") {
			REQUIRE(arr.end() != arr.begin());
		}
	}
}