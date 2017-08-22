// STD
#include <forward_list>
#include <list>
#include <vector>

// Catch
#include <catch.hpp>

// Boon
#include <Boon/algorithm.hpp>

// BoonTest
#include <BoonTest/Search/search_algorithm_test.hpp>


TEST_CASE("Algorithm: linear_search", "[linear_search][algorithm]") {
	GIVEN("a forward iterating container") {
		using Container = std::forward_list<int>;
		
		THEN("the container iterator has the correct iterator category") {
			using cat = std::iterator_traits<Container::iterator>::iterator_category;
			constexpr auto same = std::is_same<cat, std::forward_iterator_tag>::value;
			REQUIRE(same);
		}

		SEARCH_ALGORITHM_TEST("Boon::linear_search - forward_iterator", Boon::linear_search, Container);

	}

	GIVEN("a bidirectional iterating container") {
		using Container = std::list<int>;

		THEN("the container iterator has the correct iterator category") {
			using cat = std::iterator_traits<Container::iterator>::iterator_category;
			constexpr auto same = std::is_same<cat, std::bidirectional_iterator_tag>::value;
			REQUIRE(same);
		}

		SEARCH_ALGORITHM_TEST("Boon::linear_search - bidirectional_iterator", Boon::linear_search, Container);
	}

	GIVEN("a random access iterating container") {
		using Container = std::vector<int>;

		THEN("the container iterator has the correct iterator category") {
			using cat = std::iterator_traits<Container::iterator>::iterator_category;
			constexpr auto same = std::is_same<cat, std::random_access_iterator_tag>::value;
			REQUIRE(same);
		}

		SEARCH_ALGORITHM_TEST("Boon::linear_search - random_access_iterator", Boon::linear_search, Container);
	}
}