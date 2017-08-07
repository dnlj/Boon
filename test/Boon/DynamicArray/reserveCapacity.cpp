// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: reserveCapacity", "[DynamicArray][reserverCapacity]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		THEN("capacity is greater or equal to it's size") {
			REQUIRE(arr.capacity() >= arr.size());
		}

		WHEN("capacity is reserved greater than current capacity") {
			const auto capacity = arr.capacity() + 5;

			// Make sure there was not an overflow
			REQUIRE(capacity > arr.capacity());

			arr.reserveCapacity(capacity);

			THEN("the capacity is greater than or equal to the reserved capacity") {
				REQUIRE(arr.capacity() >= capacity);
			}
		}

		WHEN("capacity is reserved equal to current capacity") {
			const auto capacity = arr.capacity();
			arr.reserveCapacity(capacity);

			THEN("the capacity is not changed") {
				REQUIRE(arr.capacity() == capacity);
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16, 32, 64};

		THEN("capacity is greater or equal to it's size") {
			REQUIRE(arr.capacity() >= arr.size());
		}

		WHEN("capacity is reserved greater than current capacity") {
			const auto capacity = arr.capacity() + 5;

			// Make sure there was not an overflow
			REQUIRE(capacity > arr.capacity());

			arr.reserveCapacity(capacity);

			THEN("the capacity is greater than or equal to the reserved capacity") {
				REQUIRE(arr.capacity() >= capacity);
			}
		}

		WHEN("capacity is reserved equal to current capacity") {
			const auto capacity = arr.capacity();
			arr.reserveCapacity(capacity);

			THEN("the capacity is not changed") {
				REQUIRE(arr.capacity() == capacity);
			}
		}

		WHEN("capacity is reserved less than current capacity") {
			const auto originalCapacity = arr.capacity();
			const auto capacity = originalCapacity - 5;

			// Make sure there was not an overflow
			REQUIRE(capacity < originalCapacity);

			arr.reserveCapacity(capacity);

			THEN("the capacity is not changed") {
				REQUIRE(arr.capacity() == originalCapacity);
			}
		}
	}
}