// Catch
#include <catch.hpp>

// Boon
#include <Boon/algorithm.hpp>

TEST_CASE("Algorithm: move", "[move][algorithm]") {
	GIVEN("two arrays of the same size") {
		int arr1[] = {1, 2, 4, 8, 16};
		constexpr auto size = std::extent<decltype(arr1)>::value;
		
		decltype(arr1) arr1Copy;
		Boon::copy(arr1, arr1 + size, arr1Copy);

		decltype(arr1) arr2;

		WHEN("the first array is moved into the second") {
			Boon::move(arr1, arr1 + size, arr2);

			THEN("the second array has the elements of the first") {
				for (size_t i = 0; i < size; ++i) {
					REQUIRE(arr1Copy[i] == arr2[i]);
				}
			}
		}
	}
}