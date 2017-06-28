// Catch
#include <catch.hpp>

// Boon
#include <Boon/IsEqualityComparable.hpp>

namespace {
	// EqualityComparable is defined in §20.5.3.1 of the ISO C++ standard
	class EqualityComparable {
		public:
			bool operator==(const EqualityComparable&);
	};
}

TEST_CASE("EqualityComparable", "[EqualityComparable]") {
	GIVEN("an EqualityComparable type") {
		THEN("then value is defined to true") {
			REQUIRE(Boon::IsEqualityComparable<EqualityComparable>::value == true);
		}
	}

	GIVEN("an non EqualityComparable type") {
		class NonEqualityComparable : public EqualityComparable {
			public: bool operator==(const NonEqualityComparable&) = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsEqualityComparable<NonEqualityComparable>::value == false);
		}
	}
}