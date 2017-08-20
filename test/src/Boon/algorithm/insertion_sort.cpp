// STD
#include <forward_list>
#include <list>
#include <vector>

// Catch
#include <catch.hpp>

// Boon
#include <Boon/algorithm.hpp>

// BoonTest
#include <BoonTest/Sort/sort_algorithm_test.hpp>


TEST_CASE("Algorithm: insertion_sort", "[insertion_sort][algorithm]") {
	GIVEN("a forward iterating container") {
		using Container = std::forward_list<int>;

		THEN("the container iterator has the correct iterator category") {
			using cat = std::iterator_traits<Container::iterator>::iterator_category;
			constexpr auto same = std::is_same<cat, std::forward_iterator_tag>::value;
			REQUIRE(same);
		}

		THEN("the algorithm is correct") {
			SORT_ALGORITHM_TEST("Boon::insertion_sort - forward_iterator", Boon::insertion_sort, Container);
		}
	}

	GIVEN("a bidirectional iterating container") {
		using Container = std::list<int>;

		THEN("the container iterator has the correct iterator category") {
			using cat = std::iterator_traits<Container::iterator>::iterator_category;
			constexpr auto same = std::is_same<cat, std::bidirectional_iterator_tag>::value;
			REQUIRE(same);
		}

		THEN("the algorithm is correct") {
			SORT_ALGORITHM_TEST("Boon::insertion_sort - bidirectional_iterator", Boon::insertion_sort, Container);
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
			SORT_ALGORITHM_TEST("Boon::insertion_sort - random_access_iterator", Boon::insertion_sort, Container);
		}
	}
}