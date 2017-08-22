// Catch
#include <catch.hpp>

// Boon
#include <Boon/type_traits.hpp>


namespace {
	class A {};
	class B {};
	class C {};

	bool operator==(const A& left, const B& right) { return true; };
}

TEST_CASE("Algorithm: is_equal_comparable", "[is_equal_comparable][is_equal_comparable_v][type_traits]") {
	GIVEN("Two equal comparable types") {
		using Left = A;
		using Right = B;

		THEN("the two types are equal comparable") {
			constexpr auto correct = Boon::is_equal_comparable<Left, Right>::value;
			constexpr auto incorrect = Boon::is_equal_comparable<Right, Left>::value;
			constexpr auto correct_v = Boon::is_equal_comparable_v<Left, Right>;
			constexpr auto incorrect_v = Boon::is_equal_comparable_v<Right, Left>;

			REQUIRE(correct);
			REQUIRE_FALSE(incorrect);
			REQUIRE(correct_v);
			REQUIRE_FALSE(incorrect_v);
		}
	}

	GIVEN("Two not equal comparable types") {
		using Left = A;
		using Right = C;

		THEN("the two types are equal comparable") {
			constexpr auto correct = Boon::is_equal_comparable<Left, Right>::value;
			constexpr auto incorrect = Boon::is_equal_comparable<Right, Left>::value;
			constexpr auto correct_v = Boon::is_equal_comparable_v<Left, Right>;
			constexpr auto incorrect_v = Boon::is_equal_comparable_v<Right, Left>;

			REQUIRE_FALSE(correct);
			REQUIRE_FALSE(incorrect);
			REQUIRE_FALSE(correct_v);
			REQUIRE_FALSE(incorrect_v);
		}
	}
}