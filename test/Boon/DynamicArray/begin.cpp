// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: begin", "[DynamicArray][begin]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		THEN("begin is equal to end") {
			REQUIRE(arr.begin() == arr.end());
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		THEN("begin is not equal to end") {
			REQUIRE(arr.begin() != arr.end());
		}

		THEN("begin has the value of the first element in the array") {
			REQUIRE(*arr.begin() == arr[0]);
		}
	}
}