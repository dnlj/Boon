// Catch
#include <catch.hpp>

// Boon
#include <Boon/algorithm.hpp>

TEST_CASE("Algorithm: copy", "[max][algorithm]") {
	GIVEN("two arrays of the same size") {
		int arr1[] = {1, 2, 4, 8, 16}; // The first five powers of two
		constexpr auto size = std::extent<decltype(arr1)>::value;

		int* arr2 = new int[size];

		WHEN("the first array is copied into the second") {
			Boon::copy(arr1, arr1 + size, arr2);

			THEN("the first array is unchanged") {
				for (size_t i = 0; i < size; ++i) {
					REQUIRE(arr1[i] == 1 << i); // powers of two
				}
			}

			THEN("the second array has the same elements of the first") {
				for (size_t i = 0; i < size; ++i) {
					REQUIRE(arr1[i] == arr2[i]);
				}
			}
		}

		delete[] arr2;
	}

	GIVEN("two arrays of different size") {
		int arr1[] = {1, 2, 4, 8, 16, 32}; // The first six powers of two
		constexpr auto size1 = std::extent<decltype(arr1)>::value;

		const auto size2 = size1/2;
		int* arr2 = new int[size2];

		WHEN("part of the first array is copied into the second") {
			Boon::copy(arr1, arr1 + size2, arr2);

			THEN("the first array is unchanged") {
				for (size_t i = 0; i < size1; ++i) {
					REQUIRE(arr1[i] == 1 << i); // powers of two
				}
			}

			THEN("the second array has the same elements of the first") {
				for (size_t i = 0; i < size2; ++i) {
					REQUIRE(arr1[i] == arr2[i]);
				}
			}
		}

		delete[] arr2;
	}
}