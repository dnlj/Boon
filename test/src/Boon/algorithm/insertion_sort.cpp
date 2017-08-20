// STD
#include <forward_list>

// Catch
#include <catch.hpp>

// Boon
#include <Boon/algorithm.hpp>

// BoonTest
#include <BoonTest/Sort/sort_algorithm_test.hpp>


TEST_CASE("Algorithm: insertion_sort", "[insertion_sort][algorithm]") {
	SORT_ALGORITHM_TEST("Boon::insertion_sort", Boon::insertion_sort, std::forward_list<int>);
}