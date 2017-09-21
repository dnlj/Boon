// STD
#include <vector>
#include <algorithm>

// Catch
#include <catch.hpp>

// Boon
#include <Boon/algorithm.hpp>


TEST_CASE("Algorithm: merge_ranges", "[merge_ranges][algorithm]") {
	using T = int;

	GIVEN("two empty containers") {
		std::vector<T> first;
		std::vector<T> second;

		WHEN("the containers are merged") {
			std::vector<T> output(first.size() + second.size());
			Boon::merge_ranges(first.begin(), first.end(), second.begin(), second.end(), output.begin());

			THEN("the resulting container is empty") {
				REQUIRE(output.empty());
			}
		}
	}

	GIVEN("an non-empty container and an empty container") {
		std::vector<T> first{1, 2, 3, 4, 5, 6};
		std::vector<T> second;

		WHEN("the containers are merged") {
			auto copy = first;
			std::vector<T> output(first.size() + second.size());
			Boon::merge_ranges(first.begin(), first.end(), second.begin(), second.end(), output.begin());

			THEN("the resulting container is equal to the non-empty container") {
				REQUIRE(output == copy);
			}
		}
	}

	GIVEN("two non-empty containers") {
		std::vector<T> first{1, 3, 5};
		std::vector<T> second{2, 4, 6};

		WHEN("the containers are merged") {
			std::vector<T> output(first.size() + second.size());
			Boon::merge_ranges(first.begin(), first.end(), second.begin(), second.end(), output.begin());

			THEN("the resulting container is equal to merged containers") {
				auto sorted = std::vector<T>{1, 2, 3, 4, 5, 6};
				REQUIRE(output == sorted);
			}
		}
	}
}