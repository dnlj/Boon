// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: rend", "[DynamicArray][rend]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		THEN("rend is equal to rbegin") {
			REQUIRE(arr.rend() == arr.rbegin());
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		THEN("rend is not equal to rbegin") {
			REQUIRE(arr.rend() != arr.rbegin());
		}
	}
}

TEST_CASE("DynamicArray: rend const", "[DynamicArray][rend]") {
	GIVEN("an empty DynamicArray") {
		const Boon::DynamicArray<int> arr;

		THEN("rend is equal to rbegin") {
			REQUIRE(arr.rend() == arr.rbegin());
		}
	}

	GIVEN("an non-empty DynamicArray") {
		const Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		THEN("rend is not equal to rbegin") {
			REQUIRE(arr.rend() != arr.rbegin());
		}
	}
}