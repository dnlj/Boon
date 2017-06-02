// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: getFront", "[DynamicArray][getFront]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("getFront is called") {
			THEN("and exception is thrown") {
				REQUIRE_THROWS_AS(arr.getFront(), std::out_of_range);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {

		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("getFront is called") {
			THEN("the first element of the array is returned") {
				REQUIRE(arr.getFront() == 1);
			}
		}
	}
}

TEST_CASE("DynamicArray: getFront - const", "[DynamicArray][getFront]") {
	GIVEN("an empty DynamicArray") {
		const Boon::DynamicArray<int> arr;

		WHEN("getFront is called") {
			THEN("and exception is thrown") {
				REQUIRE_THROWS_AS(arr.getFront(), std::out_of_range);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {

		const Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("getFront is called") {
			THEN("the first element of the array is returned") {
				REQUIRE(arr.getFront() == 1);
			}
		}
	}
}