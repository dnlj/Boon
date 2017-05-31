// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: clear", "[DynamicArray][clear]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("the array is cleared") {
			const auto capacity = arr.getCapacity();
			arr.clear();

			THEN("the capacity does not change") {
				REQUIRE(capacity == arr.getCapacity());
			}

			THEN("the array is empty") {
				REQUIRE(arr.isEmpty());
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("the array is cleared") {
			const auto capacity = arr.getCapacity();
			arr.clear();

			THEN("the capacity does not change") {
				REQUIRE(capacity == arr.getCapacity());
			}

			THEN("the array is empty") {
				REQUIRE(arr.isEmpty());
			}
		}
	}
}