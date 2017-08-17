// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: front", "[DynamicArray][front]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("front is called") {
			THEN("and exception is thrown") {
				REQUIRE_THROWS_AS(arr.front(), std::out_of_range);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {

		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("front is called") {
			THEN("the first element of the array is returned") {
				REQUIRE(arr.front() == 1);
			}
		}
	}
}

TEST_CASE("DynamicArray: front - const", "[DynamicArray][front]") {
	GIVEN("an empty DynamicArray") {
		const Boon::DynamicArray<int> arr;

		WHEN("front is called") {
			THEN("and exception is thrown") {
				REQUIRE_THROWS_AS(arr.front(), std::out_of_range);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {

		const Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("front is called") {
			THEN("the first element of the array is returned") {
				REQUIRE(arr.front() == 1);
			}
		}
	}
}