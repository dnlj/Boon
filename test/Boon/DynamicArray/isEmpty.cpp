// Catch
#include <catch.hpp>

// Boon
#include <Boon/DynamicArray.hpp>

TEST_CASE("DynamicArray: isEmpty", "[DynamicArray][isEmpty]") {
	GIVEN("an empty DynamicArray") {
		Boon::DynamicArray<int> arr;

		THEN("the DynamicArray is empty") {
			REQUIRE(arr.isEmpty());
		}
	}

	GIVEN("an non-empty DynamicArray") {
		Boon::DynamicArray<int> arr{1, 2, 4, 8, 16};

		THEN("the DynamicArray is not empty") {
			REQUIRE(!arr.isEmpty());
		}
	}
}