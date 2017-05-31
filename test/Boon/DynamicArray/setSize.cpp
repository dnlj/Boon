// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: setSize", "[DynamicArray][setSize]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		THEN("the size is zero") {
			REQUIRE(arr.getSize() == 0);
		}

		WHEN("the size is set but not changed") {
			// Set our new size
			arr.setSize(0);

			THEN("the size does not change") {
				// The size does not change
				REQUIRE(arr.getSize() == 0);
			}
		}

		WHEN("the size is increased without an inital value") {
			constexpr size_t newSize = 16;

			// Set our new size
			arr.setSize(newSize);

			THEN("the size increases and new values are default initialized") {
				// The size should increases
				REQUIRE(arr.getSize() == newSize);
				REQUIRE(arr.getCapacity() >= newSize);

				// New values are default initialized
				for (size_t i = 0; i < newSize; ++i) {
					REQUIRE(arr[i] == int{});
				}
			}
		}

		WHEN("the size is increased with an inital value") {
			constexpr size_t newSize = 16;
			constexpr int newValue = -64;

			// Set our new size
			arr.setSize(newSize, newValue);

			THEN("the size increases and new values are set") {
				// The size increases
				REQUIRE(arr.getSize() == newSize);
				REQUIRE(arr.getCapacity() >= newSize);

				// New values are set
				for (size_t i = 0; i < newSize; ++i) {
					REQUIRE(arr[i] == newValue);
				}
			}
		}
	}

	GIVEN("an non empty DynamicArray") {
		constexpr size_t initSize = 8;
		constexpr int initValue = 32;

		// Create the array
		Boon::DynamicArray<int> arr(initSize, initValue);

		THEN("the size and capacity are non-zero") {
			REQUIRE(arr.getSize() == initSize);
			REQUIRE(arr.getCapacity() >= initSize);
		}

		WHEN("the size is set but not changed") {
			constexpr size_t newSize = initSize;
			
			// Store a copy of our old array
			auto arrCopy = arr;

			// Set our new size
			arr.setSize(newSize);

			THEN("the size and values do not change") {
				// The size does not change
				REQUIRE(arr.getSize() == arrCopy.getSize());
				REQUIRE(arr.getCapacity() >= arrCopy.getCapacity());

				// Values do not change
				for (size_t i = 0; i < arr.getSize(); ++i) {
					REQUIRE(arr[i] == arrCopy[i]);
				}
			}
		}

		WHEN("the size is increased without an inital value") {
			constexpr size_t newSize = 16;

			// Make sure our new size is larger than our old size
			REQUIRE(newSize > initSize);

			// Set our new size
			arr.setSize(newSize);

			THEN ("the size increases, old values are unchanged, and new values are default initialized") {
				// The size should increases
				REQUIRE(arr.getSize() == newSize);
				REQUIRE(arr.getCapacity() >= newSize);

				// Old values are unchanged
				for (size_t i = 0; i < initSize; ++i) {
					REQUIRE(arr[i] == initValue);
				}

				// New values are default initialized
				for (size_t i = initSize; i < newSize; ++i) {
					REQUIRE(arr[i] == int{});
				}
			}
		}

		WHEN("the size is increased with an inital value") {
			constexpr size_t newSize = 16;
			constexpr int newValue = -64;

			// Make sure our new size is larger than our old size
			REQUIRE(newSize > initSize);

			// Set our new size
			arr.setSize(newSize, newValue);

			THEN("the size increases, old values are unchanged, and new values are set") {
				// The size increases
				REQUIRE(arr.getSize() == newSize);
				REQUIRE(arr.getCapacity() >= newSize);

				// Old values are unchanged
				for (size_t i = 0; i < initSize; ++i) {
					REQUIRE(arr[i] == initValue);
				}

				// New values are set
				for (size_t i = initSize; i < newSize; ++i) {
					REQUIRE(arr[i] == newValue);
				}
			}
		}

		WHEN("the size is decreased without an inital value") {
			constexpr size_t newSize = 4;

			// Make sure our new size is less than our old size
			REQUIRE(newSize < initSize);

			// Set our new size
			arr.setSize(newSize);

			THEN("the size decreases and old values are unchanged") {
				// The size decreases
				REQUIRE(arr.getSize() == newSize);
				REQUIRE(arr.getCapacity() >= newSize);

				// Old values are unchanged
				for (size_t i = 0; i < newSize; ++i) {
					REQUIRE(arr[i] == initValue);
				}
			}
		}

		WHEN("the size is decreased with an inital value") {
			constexpr size_t newSize = 4;
			constexpr int newValue = -64;

			// Make sure our new size is less than our old size
			REQUIRE(newSize < initSize);

			// Set our new size
			arr.setSize(newSize, newValue);

			THEN("the size decreases and old values are unchanged") {
				// The size decreases
				REQUIRE(arr.getSize() == newSize);
				REQUIRE(arr.getCapacity() >= newSize);

				// Old values are unchanged
				for (size_t i = 0; i < newSize; ++i) {
					REQUIRE(arr[i] == initValue);
				}
			}
		}
	}
}