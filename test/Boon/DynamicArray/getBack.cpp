// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: getBack", "[DynamicArray][getBack]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("getBack is called") {
			THEN("and exception is thrown") {
				REQUIRE_THROWS_AS(arr.getBack(), std::out_of_range);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("getBack is called") {
			THEN("the last element of the array is returned") {
				REQUIRE(arr.getBack() == 16);
			}
		}
	}
}

TEST_CASE("DynamicArray: getBack - const", "[DynamicArray][getBack]") {
	GIVEN("an empty DynamicArray") {
		const Boon::DynamicArray<int> arr;

		WHEN("getBack is called") {
			THEN("and exception is thrown") {
				REQUIRE_THROWS_AS(arr.getBack(), std::out_of_range);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		const Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("getBack is called") {
			THEN("the last element of the array is returned") {
				REQUIRE(arr.getBack() == 16);
			}
		}
	}
}