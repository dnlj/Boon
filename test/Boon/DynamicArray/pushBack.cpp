// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: pushBack", "[DynamicArray][pushBack]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("an value is pushed back") {
			constexpr int value = 32;
			arr.pushBack(value);

			THEN("the size of the array is increased") {
				REQUIRE(arr.getSize() == 1);
			}

			THEN("the value in the array is equal to the value that was pushed back") {
				REQUIRE(arr[0] == value);
			}
		}
	}
	
	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};
		const auto copy = arr;

		WHEN("an value is pushed back") {
			constexpr int value = 32;
			arr.pushBack(value);

			THEN("the size of the array is increased") {
				REQUIRE(arr.getSize() == copy.getSize() + 1);
			}

			THEN("the value in the array is equal to the value that was pushed back") {
				REQUIRE(arr[arr.getSize() - 1] == value);
			}

			THEN("the other values in the array are not modified") {
				for (int i = 0; i < copy.getSize(); ++i) {
					REQUIRE(copy[i] == arr[i]);
				}
			}
		}
	}
}