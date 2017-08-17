// Catch
#include <catch.hpp>

// Boon
#include <Boon/algorithm.hpp>


TEST_CASE("Algorithm: min - one argument", "[min][algorithm]") {
	constexpr int a = 0;

	GIVEN("one value a") {
		THEN("the return value is equal to the input value") {
			REQUIRE(Boon::min(a) == a);
		}
	}
}

TEST_CASE("Algorithm: min - multiple arguments", "[min][algorithm]") {
	constexpr int a = 0;

	GIVEN("two values a, b") {
		WHEN("a is greater than b") {
			constexpr int b = -100;

			THEN("the return value is equal to b") {
				REQUIRE(Boon::min(a, b) == b);
			}
		}

		WHEN("a is equal to b") {
			constexpr int b = a;

			THEN("the return value is equal to a and b") {
				REQUIRE(Boon::min(a, b) == a);
			}
		}

		WHEN("a is less than b") {
			constexpr int b = 100;

			THEN("the return value is equal to a") {
				REQUIRE(Boon::min(a, b) == a);
			}
		}
	}

	GIVEN("more than two values") {
		WHEN("all values are equal") {
			constexpr int b = a;
			constexpr int c = a;
			constexpr int d = a;
			constexpr int e = a;

			THEN("the return value is equal to the input values") {
				REQUIRE(Boon::min(e, d, c, b, a) == a);
			}
		}

		WHEN("all values are not equal") {
			constexpr int b = -50;
			constexpr int c = -25;
			constexpr int d = +25;
			constexpr int e = +50;

			THEN("the return value is equal to the minimum of the input values") {
				REQUIRE(Boon::min(e, d, c, b, a) == b);
			}
		}
	}
}

TEST_CASE("Algorithm: min - initializer list", "[min][algorithm]") {
	GIVEN("an initializer list of equal values") {
		constexpr int value = 10;

		THEN("the return value is equal to the input values") {
			REQUIRE(Boon::min({value, value, value, value, value}) == value);
		}
	}

	GIVEN("an initializer list of non equal values") {
		constexpr int a = -50;
		constexpr int b = -25;
		constexpr int c = 0;
		constexpr int d = +25;
		constexpr int e = +50;

		THEN("the return value is equal to the minimum of the input values") {
			REQUIRE(Boon::min({e, d, c, b, a}) == a);
		}
	}
}