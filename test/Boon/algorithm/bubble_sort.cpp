// STD
#include <algorithm>
#include <vector>

// Catch
#include <catch.hpp>

// Boon
#include <Boon/algorithm.hpp>
#include <Boon/DynamicArray.hpp>

namespace {
	template<class T>
	void test_bubble_sort(T unsorted_arr) {
		// Use std::sort to generate a reference
		auto sorted_arr = unsorted_arr;
		std::sort(sorted_arr.begin(), sorted_arr.end());

		// Sort the container
		Boon::bubble_sort(unsorted_arr.begin(), unsorted_arr.end());

		// Check against the reference
		for (size_t i = 0; i < sorted_arr.size(); ++i) {
			REQUIRE(unsorted_arr[i] == sorted_arr[i]);
		}
	}
}

TEST_CASE("Algorithm: bubble_sort", "[bubble_sort][algorithm]") {
	test_bubble_sort(Boon::DynamicArray<int>{});
	test_bubble_sort(Boon::DynamicArray<int>{0});
	test_bubble_sort(Boon::DynamicArray<int>{2, -2});
	test_bubble_sort(Boon::DynamicArray<int>{+4, +2, +1, 0, -1, -2, -4});
	test_bubble_sort(Boon::DynamicArray<int>{-2, 0, +2, +4, -1, +1, -4});
	test_bubble_sort(std::vector<int>{+4, +2, +1, 0, -1, -2, -4});
	test_bubble_sort(std::vector<int>{-2, 0, +2, +4, -1, +1, -4});

	GIVEN("an sorted array") {
		const Boon::DynamicArray<int> sorted_arr = {-4, -2, -1, 0, +1, +2, +4};
		Boon::DynamicArray<int> arr = sorted_arr;

		WHEN("The array is sorted") {
			Boon::bubble_sort(arr.begin(), arr.end());

			THEN("the array remains sorted") {
				for (size_t i = 0; i < sorted_arr.size(); ++i) {
					REQUIRE(arr[i] == sorted_arr[i]);
				}
			}
		}
	}
}