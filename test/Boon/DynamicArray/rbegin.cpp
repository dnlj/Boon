// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>


TEST_CASE("DynamicArray: rbegin", "[DynamicArray][rbegin]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		THEN("rbegin is equal to rend") {
			REQUIRE(arr.rbegin() == arr.rend());
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		THEN("rbegin is not equal to rend") {
			REQUIRE(arr.rbegin() != arr.rend());
		}

		THEN("rbegin has the value of the last element in the array") {
			REQUIRE(*arr.rbegin() == arr[arr.size() - 1]);
		}
	}
}

TEST_CASE("DynamicArray: rbegin const", "[DynamicArray][rbegin]") {
	GIVEN("an empty DynamicArray") {
		const Boon::DynamicArray<int> arr;

		THEN("rbegin is equal to rend") {
			REQUIRE(arr.rbegin() == arr.rend());
		}
	}

	GIVEN("an non-empty DynamicArray") {
		const Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		THEN("rbegin is not equal to rend") {
			REQUIRE(arr.rbegin() != arr.rend());
		}

		THEN("rbegin has the value of the last element in the array") {
			REQUIRE(*arr.rbegin() == arr[arr.size() - 1]);
		}
	}
}