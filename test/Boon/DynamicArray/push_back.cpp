// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: push_back", "[DynamicArray][push_back]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("an value is pushed back") {
			constexpr int value = 32;
			arr.push_back(value);

			THEN("the size of the array is increased") {
				REQUIRE(arr.size() == 1);
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
			arr.push_back(value);

			THEN("the size of the array is increased") {
				REQUIRE(arr.size() == copy.size() + 1);
			}

			THEN("the value in the array is equal to the value that was pushed back") {
				REQUIRE(arr[arr.size() - 1] == value);
			}

			THEN("the other values in the array are not modified") {
				for (int i = 0; i < copy.size(); ++i) {
					REQUIRE(copy[i] == arr[i]);
				}
			}
		}
	}
}

TEST_CASE("DynamicArray: push_back - move", "[DynamicArray][push_back]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		WHEN("an value is pushed back") {
			int value = 32;
			arr.push_back(std::move(value));

			THEN("the size of the array is increased") {
				REQUIRE(arr.size() == 1);
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
			int value = 32;
			arr.push_back(std::move(value));

			THEN("the size of the array is increased") {
				REQUIRE(arr.size() == copy.size() + 1);
			}

			THEN("the value in the array is equal to the value that was pushed back") {
				REQUIRE(arr[arr.size() - 1] == value);
			}

			THEN("the other values in the array are not modified") {
				for (int i = 0; i < copy.size(); ++i) {
					REQUIRE(copy[i] == arr[i]);
				}
			}
		}
	}
}