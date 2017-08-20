// STD
#include <vector>

// Catch
#include <catch.hpp>

// Boon
#include <Boon/algorithm.hpp>

// BoonTest
#include <BoonTest/Sort/sort_algorithm_test.hpp>


TEST_CASE("Algorithm: bubble_sort", "[bubble_sort][algorithm]") {
	SORT_ALGORITHM_TEST("Boon::bubble_sort", Boon::bubble_sort, std::vector<int>);
}