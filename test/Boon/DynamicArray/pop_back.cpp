// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: pop_back", "[DynamicArray][pop_back]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("pop_back is called an exception is thrown") {
			REQUIRE_THROWS(arr.pop_back());
		}
	}

	GIVEN("a non-empty DynamicArray") {
		const Boon::DynamicArray<int> arr_reference{1, 2, 4, 8, 16};
		Boon::DynamicArray<int> arr = arr_reference;
		
		WHEN("pop_back is called") {
			arr.pop_back();

			THEN("the last element in the array is removed") {
				for (size_t i = 0; i < arr.getSize(); ++i) {
					REQUIRE(arr[i] == arr_reference[i]);
				}
			}
		}
	}
}