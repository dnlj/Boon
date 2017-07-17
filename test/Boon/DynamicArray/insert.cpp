// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

// TODO: Add test for the iterator versions
// TODO: Add test for the count versions
TEST_CASE("DynamicArray: insert - index", "[DynamicArray][insert]") {
	GIVEN("an empty DynamicArray") {
		constexpr int value = 32;
		Boon::DynamicArray<int> arr;

		WHEN("an item is inserted at the beginning/end") {
			const auto it = arr.insert(0, value);

			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size increases") {
				REQUIRE(arr.getSize() == 1);
			}
			
			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[0] == value);
			}
		}

		WHEN("an item is inserted past the end") {
			THEN("an error is thrown") {
				REQUIRE_THROWS_AS(arr.insert(1, value), std::out_of_range);
			}
			
			THEN("the size is not changed") {
				REQUIRE(arr.getSize() == 0);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{2, 4, 8, 16, 32};
		const auto reference = arr;
		const size_t initialSize = arr.getSize();

		WHEN("an item is inserted at the beginning") {
			constexpr int value = 1;
			const auto it = arr.insert(0, value);
			
			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size of the array increases by one") {
				REQUIRE(arr.getSize() == initialSize + 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[0] == value);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 1; i < arr.getSize(); ++i) {
					REQUIRE(reference[i - 1] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted at the end") {
			constexpr int value = 64;
			const auto it = arr.insert(initialSize, value);
			
			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size of the array increases") {
				REQUIRE(arr.getSize() == initialSize + 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[initialSize] == value);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 0; i < reference.getSize(); ++i) {
					REQUIRE(reference[i] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted between the beginning and end") {
			constexpr int value = 64;
			constexpr size_t index = 2;
			const auto it = arr.insert(index, value);
			
			THEN("the returned value of the iterator is equal to the value inserted") {
				REQUIRE(*it == value);
			}

			THEN("the size of the array increases by one") {
				REQUIRE(arr.getSize() == initialSize + 1);
			}

			THEN("the item at that position has the corresponding value") {
				REQUIRE(arr[index] == value);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 0; i < arr.getSize(); ++i) {
					if (i == index) { continue; }
					REQUIRE(reference[i - (i > index ? 1 : 0)] == arr[i]);
				}
			}
		}

		WHEN("an item is inserted past the end") {
			THEN("an error is thrown") {
				REQUIRE_THROWS_AS(
					arr.insert(initialSize + 1, 32),
					std::out_of_range
				);
			}

			THEN("the other items are unchanged") {
				for (size_t i = 1; i < arr.getSize(); ++i) {
					REQUIRE(reference[i] == arr[i]);
				}
			}
		}
	}
}
