// STD
#include <algorithm>
#include <string>
#include <string_view>

// Catch
#include <catch.hpp>

namespace BoonTest::Search {
	template<class Container, class Search, class Value>
	void check_search(Container& container, Search search, Value value) {
		// Use std::find to get a reference
		const auto reference = std::find(std::begin(container), std::end(container), value);

		// Search the container using our search
		const auto found = search(std::begin(container), std::end(container), value);

		// Check that our search result matches the reference
		REQUIRE(reference == found);
	}

	template<class Container, class Search>
	void search_algorithm_test(const std::string_view unique_name, Search search) {
		SECTION(std::string{"Test search algorithm: "}.append(unique_name)) {
			GIVEN("an empty container") {
				check_search(Container{}, search, 0);
			}

			GIVEN("a container with one element") {
				check_search(Container{0}, search, 0);
			}

			GIVEN("a container with two elements in reverse order") {
				check_search(Container{2, -2}, search, -2);
			}

			GIVEN("a container with two elements in order") {
				check_search(Container{-2, 2}, search, -2);
			}

			GIVEN("a container with many elements in reverse order") {
				check_search(Container{4, 2, 1, 0, -1, -2, -4}, search, -1);
			}

			GIVEN("a container with many elements in random order") {
				check_search(Container{-2, 0, 2, 4, -1, 1, -4}, search, -1);
			}

			GIVEN("a container with many elements in order") {
				check_search(Container{-4, -2, -1, 0, 1, 2, 4}, search, -1);
			}

			GIVEN("a container with duplicates") {
				check_search(Container{4, 2, 1, 0, 1, 2, 4}, search, 1);
			}

			GIVEN("a container with only duplicates") {
				check_search(Container{4, 4, 4, 4, 4, 4, 4}, search, 4);
			}

			GIVEN("an invalid search") {
				check_search(Container{-4, -2, -1, 0, 1, 2, 4}, search, 5);
				check_search(Container{-4, -2, -1, 0, 1, 2, 4}, search, -5);
			}
		}
	}

	#define SEARCH_ALGORITHM_TEST(name, func, container) {\
		using Iterator = container::iterator;\
		BoonTest::Search::search_algorithm_test<container>(name, func<Iterator, std::iterator_traits<Iterator>::value_type>);\
	}
}