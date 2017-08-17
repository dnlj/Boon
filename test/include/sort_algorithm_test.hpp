// STD
#include <algorithm>
#include <vector>
#include <string>
#include <string_view>

// Catch
#include <catch.hpp>

template<class Container, class Sort>
void compare_sort(Container container, Sort sort) {
	// Use std::sort to get a reference sort
	auto reference = container;
	std::sort(std::begin(reference), std::end(reference));

	// Sort the container using our sort
	sort(std::begin(container), std::end(container));

	// Check that our sort matches the reference
	REQUIRE(std::size(reference) == std::size(container));
	for (size_t i = 0; i < std::size(container); ++i) {
		REQUIRE(container[i] == reference[i]);
	}
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

#define SORT_ALGORITHM_TEST(name, func) {\
	using Container = std::vector<int>;\
	using Iterator = Container::iterator;\
	sort_algorithm_test<Container>(name, func<Iterator>);\
}