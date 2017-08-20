// STD
#include <list>
#include <vector>

// Catch
#include <catch.hpp>

// Boon
#include <Boon/algorithm.hpp>

// BoonTest
#include <BoonTest/Sort/sort_algorithm_test.hpp>


TEST_CASE("Algorithm: bubble_sort", "[bubble_sort][algorithm]") {
	GIVEN("a bidirectional iterating container") {
		using Container = std::list<int>;

		THEN("the container iterator has the correct iterator category") {
			using cat = std::iterator_traits<Container::iterator>::iterator_category;
			constexpr auto same = std::is_same<cat, std::bidirectional_iterator_tag>::value;
			REQUIRE(same);
		}

		THEN("the algorithm is correct") {
			SORT_ALGORITHM_TEST("Boon::bubble_sort - bidirectional_iterator", Boon::bubble_sort, Container);
		}
	}

	GIVEN("a random access iterating container") {
		using Container = std::vector<int>;

		THEN("the container iterator has the correct iterator category") {
			using cat = std::iterator_traits<Container::iterator>::iterator_category;
			constexpr auto same = std::is_same<cat, std::random_access_iterator_tag>::value;
			REQUIRE(same);
		}

		THEN("the algorithm is correct") {
			SORT_ALGORITHM_TEST("Boon::bubble_sort - random_access_iterator", Boon::bubble_sort, Container);
		}
	}
}