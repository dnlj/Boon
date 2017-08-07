// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: data", "[DynamicArray][data]") {
	GIVEN("a empty DynamicArray") {
		Boon::DynamicArray<int> arr{};

		WHEN("data is called") {
			auto data = arr.data();

			THEN("the returned value is equal to the internal array or nullptr") {
				REQUIRE((data == nullptr || data == &arr[0]));
			}
		}
	}

	GIVEN("a non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("data is called") {
			auto data = arr.data();
			
			THEN("the returned value is equal to the internal array") {
				REQUIRE(data == &arr[0]);
			}

			THEN("the elements of the returned array are equal to the elements of the DynamicArray") {
				for (size_t i = 0; i < arr.size(); ++i) {
					REQUIRE(data[i] == arr[i]);
				}
			}
		}
	}
}

TEST_CASE("DynamicArray: data - const", "[DynamicArray][data]") {
	GIVEN("a empty DynamicArray") {
		const Boon::DynamicArray<int> arr{};

		WHEN("data is called") {
			auto data = arr.data();

			THEN("the returned value is equal to the internal array or nullptr") {
				REQUIRE((data == nullptr || data == &arr[0]));
			}
		}
	}

	GIVEN("a non-empty DynamicArray") {
		const Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		WHEN("data is called") {
			auto data = arr.data();

			THEN("the returned value is equal to the internal array") {
				REQUIRE(data == &arr[0]);
			}

			THEN("the elements of the returned array are equal to the elements of the DynamicArray") {
				for (size_t i = 0; i < arr.size(); ++i) {
					REQUIRE(data[i] == arr[i]);
				}
			}
		}
	}
}