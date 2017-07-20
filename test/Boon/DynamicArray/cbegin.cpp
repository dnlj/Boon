// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: cbegin const", "[DynamicArray][begin][cbegin]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		THEN("cbegin is equal to cend") {
			REQUIRE(arr.cbegin() == arr.cend());
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		THEN("cbegin is not equal to cend") {
			REQUIRE(arr.cbegin() != arr.cend());
		}

		THEN("cbegin has the value of the first element in the array") {
			REQUIRE(*arr.cbegin() == arr[0]);
		}
	}
}