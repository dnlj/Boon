// Catch
#include <catch.hpp>

// Boon
#include <Boon/algorithm.hpp>

// Test
#include <sort_algorithm_test.hpp>


TEST_CASE("Algorithm: bubble_sort", "[bubble_sort][algorithm]") {
	SORT_ALGORITHM_TEST("Boon::bubble_sort", Boon::bubble_sort);
}