// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: back", "[DynamicArray][back]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("back is called") {
			THEN("and exception is thrown") {
				REQUIRE_THROWS_AS(arr.back(), std::out_of_range);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("back is called") {
			THEN("the last element of the array is returned") {
				REQUIRE(arr.back() == 16);
			}
		}
	}
}

TEST_CASE("DynamicArray: back - const", "[DynamicArray][back]") {
	GIVEN("an empty DynamicArray") {
		const Boon::DynamicArray<int> arr;

		WHEN("back is called") {
			THEN("and exception is thrown") {
				REQUIRE_THROWS_AS(arr.back(), std::out_of_range);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		const Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("back is called") {
			THEN("the last element of the array is returned") {
				REQUIRE(arr.back() == 16);
			}
		}
	}
}