// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: getAt", "[DynamicArray][getAt]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("getAt is called") {
			constexpr size_t index = 0;
			THEN("and exception is thrown") {
				REQUIRE_THROWS_AS(arr.getAt(index), std::out_of_range);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("getAt is called with a index less than the size") {
			THEN("the element of the array at index is returned") {
				for(size_t i = 0; i < arr.getSize(); ++i) {
					REQUIRE(arr.getAt(i) == arr[i]);
				}
			}
		}

		WHEN("getAt is called with a index equal to the size") {
			size_t index = arr.getSize();

			THEN("and exception is thrown") {
				REQUIRE_THROWS_AS(arr.getAt(index), std::out_of_range);
			}
		}

		WHEN("getAt is called with a index greater than the size") {
			size_t index = arr.getSize() + 1;

			THEN("and exception is thrown") {
				REQUIRE_THROWS_AS(arr.getAt(index), std::out_of_range);
			}
		}
	}
}