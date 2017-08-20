// STD
#include <algorithm>
#include <string>
#include <string_view>

// Catch
#include <catch.hpp>

namespace BoonTest::Sort {
	template<class Container, class SFINAE = void>
	class SortSelector {
		public:
			static void sort(Container& container) {
				std::sort(std::begin(container), std::end(container));
			}
	};

	template<class Container>
	class SortSelector<Container, std::void_t<decltype(std::declval<Container>().sort())>> {
		public:
			static void sort(Container& container) {
				container.sort();
			}
	};


	template<class Container, class Sort>
	void compare_sort(Container& container, Sort sort) {
		// Use std::sort to get a reference sort
		auto reference = container;
		SortSelector<Container>::sort(reference);

		// Sort the container using our sort
		sort(std::begin(container), std::end(container));

		// Check that our sort matches the reference
		REQUIRE(reference == container);
	}


	template<class Container, class Sort>
	void sort_algorithm_test(const std::string_view unique_name, Sort sort) {
		SECTION(std::string{"Test sorting algorithm: "}.append(unique_name)) {
			GIVEN("an empty container") {
				compare_sort(Container{}, sort);
			}

			GIVEN("a container with one element") {
				compare_sort(Container{0}, sort);
			}

			GIVEN("a container with two elements in reverse order") {
				compare_sort(Container{2, -2}, sort);
			}

			GIVEN("a container with two elements in order") {
				compare_sort(Container{-2, 2}, sort);
			}

			GIVEN("a container with many elements in reverse order") {
				compare_sort(Container{4, 2, 1, 0, -1, -2, -4}, sort);
			}

			GIVEN("a container with many elements in random order") {
				compare_sort(Container{-2, 0, 2, 4, -1, 1, -4}, sort);
			}

			GIVEN("a container with many elements in order") {
				compare_sort(Container{-4, -2, -1, 0, 1, 2, 4}, sort);
			}
		}
	}

	#define SORT_ALGORITHM_TEST(name, func, container) {\
		using Iterator = container::iterator;\
		BoonTest::Sort::sort_algorithm_test<container>(name, func<Iterator>);\
	}
}