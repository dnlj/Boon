// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: shrink_to_fit", "[DynamicArray][shrink_to_fit]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("the array is shrunk to fit") {
			auto size = arr.size();
			arr.shrink_to_fit();

			THEN("the size is not changed") {
				REQUIRE(arr.size() == size);
			}

			THEN("the capacity is equal to the size") {
				REQUIRE(arr.capacity() == arr.size());
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4 ,8 ,16};

		WHEN("the array is shrunk to fit") {
			auto size = arr.size();
			arr.shrink_to_fit();

			THEN("the size is not changed") {
				REQUIRE(arr.size() == size);
			}

			THEN("the capacity is equal to the size") {
				REQUIRE(arr.capacity() == arr.size());
			}
		}
	}

	GIVEN("an empty reserved DynamicArray") {
		constexpr size_t capacity = 32;
		Boon::DynamicArray<int> arr;
		arr.reserve(capacity);

		WHEN("the array is shrunk to fit") {
			auto size = arr.size();
			arr.shrink_to_fit();

			THEN("the size is not changed") {
				REQUIRE(arr.size() == size);
			}

			THEN("the capacity is equal to the size") {
				REQUIRE(arr.capacity() == arr.size());
			}
		}
	}

	GIVEN("an non-empty reserved DynamicArray") {
		constexpr size_t capacity = 32;
		Boon::DynamicArray<int> arr{1, 2, 4 ,8 ,16};
		arr.reserve(capacity);

		WHEN("the array is shrunk to fit") {
			auto size = arr.size();
			arr.shrink_to_fit();

			THEN("the size is not changed") {
				REQUIRE(arr.size() == size);
			}

			THEN("the capacity is equal to the size") {
				REQUIRE(arr.capacity() == arr.size());
			}
		}
	}
}