// Catch
#include <catch.hpp>

// STD
#include <type_traits>
#include <vector>
#include <iostream>

// Boon
#include <Boon/IsIterator.hpp>

namespace {
	// As specified in §27.2.2/2.2 of the ISO C++ standard.
	template<class T>
	class Iterator {
		public:
			Iterator(const Iterator<T>&);
			Iterator& operator=(const Iterator&);
			~Iterator();
			T& operator*();
			Iterator& operator++();
	};
}

TEST_CASE("IsIterator", "[IsIterator]") {
	using T = int;
	using It = Iterator<T>;

	GIVEN("an iterator type") {
		THEN("then value is defined to true") {
			REQUIRE(Boon::IsIterator<It>::value == true);
		}
	}

	GIVEN("an iterator (from std)") {
		using ItStd = std::vector<int>::iterator;

		THEN("then value is defined to true") {
			REQUIRE(Boon::IsIterator<ItStd>::value == true);
		}
	}

	GIVEN("an non-iterator type (not CopyConstructible)") {
		class NonIt : public It {
			public: NonIt(const NonIt&) = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non-iterator type (not CopyAssignable)") {
		class NonIt : public It {
			public: NonIt& operator=(const NonIt&) = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non-iterator type (not Destructible)") {
		class NonIt : public It {
			public: ~NonIt() = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non-iterator type (no operator*)") {
		class NonIt : public It {
			public: T& NonIt::operator*() = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non-iterator type (no operator++)") {
		class NonIt : public It {
			public: NonIt& operator++() = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsIterator<NonIt>::value == false);
		}
	}

	GIVEN("an non-iterator type (wrong return type operator++)") {
		class NonIt : public It {
			public: NonIt& operator++() = delete;
		};

		THEN("then value is defined to false") {
			REQUIRE(Boon::IsIterator<NonIt>::value == false);
		}
	}
}