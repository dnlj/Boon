// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: crbegin", "[DynamicArray][crbegin]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		THEN("crbegin is equal to crend") {
			REQUIRE(arr.crbegin() == arr.crend());
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		THEN("crbegin is not equal to crend") {
			REQUIRE(arr.crbegin() != arr.crend());
		}

		THEN("crbegin has the value of the last element in the array") {
			REQUIRE(*arr.crbegin() == arr[arr.getSize() - 1]);
		}
	}
}