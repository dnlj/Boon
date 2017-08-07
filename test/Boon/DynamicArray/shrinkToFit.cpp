// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: shrinkToFit", "[DynamicArray][shrinkToFit]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("the array is shrunk to fit") {
			auto size = arr.size();
			arr.shrinkToFit();

			THEN("the size is not changed") {
				REQUIRE(arr.size() == size);
			}

			THEN("the capacity is equal to the size") {
				REQUIRE(arr.getCapacity() == arr.size());
			}
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4 ,8 ,16};

		WHEN("the array is shrunk to fit") {
			auto size = arr.size();
			arr.shrinkToFit();

			THEN("the size is not changed") {
				REQUIRE(arr.size() == size);
			}

			THEN("the capacity is equal to the size") {
				REQUIRE(arr.getCapacity() == arr.size());
			}
		}
	}

	GIVEN("an empty reserved DynamicArray") {
		constexpr size_t capacity = 32;
		Boon::DynamicArray<int> arr;
		arr.reserveCapacity(capacity);

		WHEN("the array is shrunk to fit") {
			auto size = arr.size();
			arr.shrinkToFit();

			THEN("the size is not changed") {
				REQUIRE(arr.size() == size);
			}

			THEN("the capacity is equal to the size") {
				REQUIRE(arr.getCapacity() == arr.size());
			}
		}
	}

	GIVEN("an non-empty reserved DynamicArray") {
		constexpr size_t capacity = 32;
		Boon::DynamicArray<int> arr{1, 2, 4 ,8 ,16};
		arr.reserveCapacity(capacity);

		WHEN("the array is shrunk to fit") {
			auto size = arr.size();
			arr.shrinkToFit();

			THEN("the size is not changed") {
				REQUIRE(arr.size() == size);
			}

			THEN("the capacity is equal to the size") {
				REQUIRE(arr.getCapacity() == arr.size());
			}
		}
	}
}